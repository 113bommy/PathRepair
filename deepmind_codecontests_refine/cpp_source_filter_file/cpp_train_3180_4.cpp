#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, MAX = 1005;
int N, zero[MAX][MAX][8], dy[8] = {0, 0, 1, -1, 1, 1, -1, -1},
                          dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
char A[MAX][MAX];
double B[MAX][MAX], C[MAX][MAX][4];
void print(double ***x, int d) {
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      printf("%.2lf%c", x[i][j][d], j == N ? '\n' : ' ');
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%s", &A[i][1]);
  for (int i = 0; i <= N + 1; ++i)
    A[i][0] = A[i][N + 1] = A[0][i] = A[N + 1][i] = '0';
  bool flag = false;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) {
      flag = flag || A[i][j] != '0';
      B[i][j] = (A[i][j] == '0' || A[i][j] == '1') ? 0.0 : log(A[i][j] - '0');
      for (int d = 0; d < 8; ++d)
        if (d == 0 || d == 4 || d == 2) {
          int ii = i - dy[d], jj = j - dx[d];
          zero[i][j][d] = A[i][j] == '0' ? 0 : zero[ii][jj][d] + 1;
        }
    }
  if (flag) return 0 * printf("0\n");
  for (int i = 1; i <= N; ++i)
    for (int j = N; j >= 0; --j) {
      for (int d = 0; d < 8; ++d)
        if (d == 5 || d == 1) {
          int ii = i - dy[d], jj = j - dx[d];
          zero[i][j][d] = A[i][j] == '0' ? 0 : zero[ii][jj][d] + 1;
        }
    }
  for (int i = N; i >= 1; --i)
    for (int j = N; j >= 0; --j) {
      for (int d = 0; d < 8; ++d)
        if (d == 7 || d == 3) {
          int ii = i - dy[d], jj = j - dx[d];
          zero[i][j][d] = A[i][j] == '0' ? 0 : zero[ii][jj][d] + 1;
        }
    }
  for (int i = N; i >= 1; --i)
    for (int j = 0; j <= N; ++j) {
      int ii = i - dy[6], jj = j - dx[6];
      zero[i][j][6] = A[i][j] == '0' ? 0 : zero[ii][jj][6] + 1;
    }
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) {
      C[i][j][0] = C[i][j - 1][0] + B[i][j];
      C[i][j][1] = C[i - 1][j][1] + B[i][j];
      C[i][j][2] = C[i - 1][j - 1][2] + B[i][j];
    }
  for (int i = 1; i <= N; ++i)
    for (int j = N; j >= 1; --j) C[i][j][3] = C[i - 1][j + 1][3] + B[i][j];
  double best = -1;
  int ti, tj, tr, ts;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (A[i][j] != '0') {
        int r[2] = {};
        double cand[2] = {};
        for (int t = 0; t < 2; ++t) {
          r[t] = 1e9;
          for (int d = t * 4; d < t * 4 + 4; ++d)
            r[t] = min(r[t], zero[i][j][d]);
          if (t == 0)
            cand[t] = (C[i][j + (r[t] - 1)][0] - C[i][j - r[t]][0]) +
                      (C[i + (r[t] - 1)][j][1] - C[i - r[t]][j][1]);
          else
            cand[t] = (C[i + (r[t] - 1)][j + (r[t] - 1)][2] -
                       C[i - r[t]][j - r[t]][2]) +
                      (C[i + (r[t] - 1)][j - (r[t] - 1)][3] -
                       C[i - r[t]][j + r[t]][3]);
          cand[t] -= B[i][j];
          if (cand[t] > best) {
            ti = i, tj = j, tr = r[t], ts = t;
            best = cand[t];
          }
        }
      }
  long long ans = 1;
  if (ts == 0) {
    for (int x = -tr + 1; x <= tr - 1; ++x) {
      ans = (ans * (A[ti + x][tj] - '0')) % MOD;
      if (x) ans = (ans * (A[ti][tj + x] - '0')) % MOD;
    }
  } else {
    for (int x = -tr + 1; x <= tr - 1; ++x) {
      ans = (ans * (A[ti + x][tj + x] - '0')) % MOD;
      if (x) ans = (ans * (A[ti + x][tj - x] - '0')) % MOD;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
