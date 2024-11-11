#include <bits/stdc++.h>
using namespace std;
int A[51];
int N;
int W[51][51];
int i, j, k, m, n;
int c[51][51][51][51];
int d[51][51][51][51][4];
void reset_c() {
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N - i + 1; j++) {
      for (m = 1; m <= N; m++) {
        for (n = 1; n <= N; n++) {
          c[i][j][m][n] = 0;
          d[i][j][m][n][0] = 0;
          d[i][j][m][n][1] = 0;
          d[i][j][m][n][2] = 0;
          d[i][j][m][n][3] = 0;
        }
      }
    }
  }
}
bool has_commom_ans(int i1, int j1, int m1, int n1, int i2, int j2, int m2,
                    int n2) {
  while (i1 >= 2) {
    int right_ans_of_1, right_ans_m, right_ans_n;
    int left_ans_of_2, left_ans_m, left_ans_n;
    if (d[i1][j1][m1][n1][1] != 0) {
      right_ans_of_1 = d[i1][j1][m1][n1][1];
      right_ans_m = d[i1][j1][m1][n1][3];
      right_ans_n = n1;
    } else {
      right_ans_of_1 = d[i1][j1][m1][n1][0];
      right_ans_m = m1;
      right_ans_n = d[i1][j1][m1][n1][2];
    }
    if (d[i2][j2][m2][n2][0] != 0) {
      left_ans_of_2 = d[i2][j2][m2][n2][0];
      left_ans_m = m2;
      left_ans_n = d[i2][j2][m2][n2][2];
    } else {
      left_ans_of_2 = d[i2][j2][m2][n2][1];
      left_ans_m = d[i2][j2][m2][n2][3];
      left_ans_n = n2;
    }
    if (right_ans_of_1 == left_ans_of_2) {
      return true;
    }
    i1 = right_ans_of_1 / 100;
    j1 = right_ans_of_1 % 100;
    m1 = right_ans_m;
    n1 = right_ans_n;
    i2 = left_ans_of_2 / 100;
    j2 = left_ans_of_2 % 100;
    m2 = left_ans_m;
    n2 = left_ans_n;
  }
  return false;
}
void print_W() {
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N - i + 1; j++) {
      cout << W[i][j] << " ";
    }
    cout << endl;
  }
}
int main(int argc, char *argv[]) {
  cin >> N;
  for (i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N - i + 1; j++) {
      cin >> W[i][j];
    }
  }
  reset_c();
  for (i = 1; i <= N; i++) {
    if (A[i] >= W[1][i]) {
      c[1][i][i][i] = A[i];
    }
  }
  for (i = 2; i <= N; i++) {
    for (j = 1; j <= N - i + 1; j++) {
      for (m = j; m <= j + i - 1; m++) {
        for (n = m; n <= j + i - 1; n++) {
          int cur_max = 0;
          int cur_max_left = 0;
          int cur_max_right = 0;
          int cur_max_leftend = 0;
          int cur_max_rightstart = 0;
          for (k = m - 1; k <= n; k++) {
            int left = c[i - 1][j][m][k];
            int right = c[i - 1][j + 1][k + 1][n];
            if (left + right >= W[i][j] && left + right > cur_max &&
                !has_commom_ans(i - 1, j, m, k, i - 1, j + 1, k + 1, n)) {
              cur_max = left + right;
              if (left != 0) {
                cur_max_left = 100 * (i - 1) + j;
                cur_max_leftend = k;
              } else {
                cur_max_left = 0;
                cur_max_leftend = k;
              }
              if (right != 0) {
                cur_max_right = 100 * (i - 1) + j + 1;
                cur_max_rightstart = k + 1;
              } else {
                cur_max_right = 0;
                cur_max_rightstart = k + 1;
              }
            }
          }
          c[i][j][m][n] = cur_max;
          d[i][j][m][n][0] = cur_max_left;
          d[i][j][m][n][1] = cur_max_right;
          d[i][j][m][n][2] = cur_max_leftend;
          d[i][j][m][n][3] = cur_max_rightstart;
        }
      }
    }
  }
  if (c[N][1][1][N] > 0) {
    cout << "Cerealguy";
  } else {
    cout << "Fat Rat";
  }
  return 0;
}
