#include <bits/stdc++.h>
using namespace std;
bool cats[21][21];
struct matrix {
  int column, row;
  long long grid[21][21];
};
const int MOD = 1000000007;
void matrix_prod(const matrix& matrix1, const matrix& matrix2,
                 matrix& new_matrix) {
  if (matrix1.column != matrix2.row) {
    new_matrix.column = 0;
    new_matrix.row = 0;
    return;
  }
  new_matrix.column = matrix2.column;
  new_matrix.row = matrix1.row;
  for (int i = 0; i < matrix1.row; i++) {
    for (int j = 0; j < matrix2.column; j++) {
      long long cur = 0;
      for (int k = 0; k < matrix1.column; k++) {
        cur += matrix1.grid[i][k] * matrix2.grid[k][j];
        cur %= MOD;
      }
      new_matrix.grid[i][j] = cur % MOD;
    }
  }
  return;
}
matrix matrix_exp(const matrix& base_matrix, long long exp) {
  matrix new_matrix;
  if (exp == 0) {
    new_matrix.column = base_matrix.column;
    new_matrix.row = base_matrix.row;
    for (int i = 0; i < new_matrix.row; i++) {
      for (int j = 0; j < new_matrix.column; j++) {
        if (j == i) {
          new_matrix.grid[i][j] = 1;
        } else {
          new_matrix.grid[i][j] = 0;
        }
      }
    }
    return new_matrix;
  }
  if (exp == 1) {
    return base_matrix;
  }
  matrix matrix_squared;
  matrix_squared.column = base_matrix.column;
  matrix_squared.row = base_matrix.row;
  matrix_prod(base_matrix, base_matrix, matrix_squared);
  if (exp % 2 == 0) {
    return matrix_exp(matrix_squared, exp / 2);
  } else {
    matrix_prod(base_matrix, matrix_exp(matrix_squared, exp / 2), new_matrix);
    return new_matrix;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  matrix A;
  A.row = n * m;
  A.column = n * m;
  memset(&(A.grid), 0, sizeof(A.grid));
  for (int i = 0; i < n * m; i++) {
    A.grid[i][i] = 1;
    if (i % m != m - 1) {
      A.grid[i][i + 1] = 1;
      A.grid[i + 1][i] = 1;
    }
    if (i + m < n * m) {
      A.grid[i][i + m] = 1;
      A.grid[i + m][i] = 1;
    }
  }
  int input[10001][4];
  for (int i = 0; i < q; i++) {
    cin >> input[i][0] >> input[i][2] >> input[i][1] >> input[i][3];
    --input[i][1];
    --input[i][2];
  }
  matrix dp1, dp2;
  dp1.column = 1;
  dp1.row = n * m;
  dp2.column = 1;
  dp2.row = n * m;
  memset(&(dp1.grid), 0, sizeof(dp1.grid));
  dp1.grid[0][0] = 1;
  matrix_prod(matrix_exp(A, input[0][3] - 1), dp1, dp2);
  for (int i = 0; i < q - 1; i++) {
    if (input[i][0] == 1) {
      if (i % 2 == 0) {
        cout << dp2.grid[input[i][1] + input[i][2] * m][0] << "\n";
      } else {
        cout << dp1.grid[input[i][1] + input[i][2] * m][0] << "\n";
      }
    } else if (input[i][0] == 2) {
      cats[input[i][1]][input[i][2]] = true;
      for (int j = 0; j < n * m; j++)
        A.grid[input[i][1] + input[i][2] * m][j] = 0;
      for (int j = 0; j < n * m; j++)
        A.grid[j][input[i][1] + input[i][2] * m] = 0;
    } else {
      cats[input[i][1]][input[i][2]] = false;
      int x = input[i][1] + input[i][2] * m;
      A.grid[x][x] = 1;
      if (input[i][1] != m - 1 && !cats[input[i][1] + 1][input[i][2]]) {
        A.grid[x][x + 1] = 1;
        A.grid[x + 1][x] = 1;
      }
      if (input[i][1] != 0 && !cats[input[i][1] - 1][input[i][2]]) {
        A.grid[x][x - 1] = 1;
        A.grid[x - 1][x] = 1;
      }
      if (input[i][2] != n - 1 && !cats[input[i][1]][input[i][2] + 1]) {
        A.grid[x][x + m] = 1;
        A.grid[x + m][x] = 1;
      }
      if (input[i][2] != 0 && !cats[input[i][1]][input[i][2] - 1]) {
        A.grid[x][x - m] = 1;
        A.grid[x - m][x] = 1;
      }
    }
    if (i % 2 == 0) {
      matrix_prod(matrix_exp(A, input[i + 1][3] - input[i][3]), dp2, dp1);
    } else {
      matrix_prod(matrix_exp(A, input[i + 1][3] - input[i][3]), dp1, dp2);
    }
  }
  if (input[q - 1][0] == 1) {
    if ((q - 1) % 2 == 0) {
      cout << dp2.grid[input[q - 1][1] + input[q - 1][2] * m][0];
    } else {
      cout << dp1.grid[input[q - 1][1] + input[q - 1][2] * m][0];
    }
  }
  return 0;
}
