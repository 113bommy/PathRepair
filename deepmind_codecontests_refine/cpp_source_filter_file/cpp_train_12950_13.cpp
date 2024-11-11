#include <bits/stdc++.h>
using namespace std;
int M[33][33];
int S[33][33];
int m;
int n;
int solve(int sid) {
  memcpy(S, M, sizeof(int) * 33 * 33);
  for (int i = 0; i < m; i++) {
    if ((1 << i) && sid) {
      for (int k = m - 1; k < n; k++) {
        for (int l = i; l < i + m; l++) {
          S[k][l] *= -1;
        }
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; i++) ret += S[m - 1][i];
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n; j++) {
      S[i][j] += S[m + i][j];
    }
  }
  for (int i = 0; i < m - 1; i++) {
    int row1 = S[i][m - 1], row2 = S[i][m - 1] * -1;
    for (int j = 0; j < m - 1; j++) {
      row1 += abs(S[i][j] + S[i][m + j]);
      row2 += abs(S[i][j] - S[i][m + j]);
    }
    ret += max(row1, row2);
  }
  return ret;
}
int main() {
  cin >> n;
  m = (n + 1) / 2;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      cin >> M[i][j];
    }
  }
  int sol = -10000000;
  for (size_t i = 0; i < (1 << m); ++i) {
    sol = max(solve(i), sol);
  }
  cout << sol << endl;
  return 0;
}
