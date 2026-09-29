#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;

            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for transpose
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], T[MAX][MAX];
    int r1, c1, r2, c2;

    // Matrix Addition
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r1, c1);

    addMatrix(A, B, C, r1, c1);

    printf("\nMatrix Addition:\n");
    displayMatrix(C, r1, c1);

    // Matrix Multiplication
    printf("\nEnter rows and columns of Matrix B for multiplication: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, r1, c1);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, r2, c2);

    if (c1 == r2) {
        multiplyMatrix(A, B, C, r1, c1, c2);

        printf("\nMatrix Multiplication:\n");
        displayMatrix(C, r1, c2);
    } else {
        printf("\nMatrix multiplication is not possible.\n");
    }

    // Transpose
    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(A, T, r1, c1);
    displayMatrix(T, c1, r1);

    return 0;
}