#include <bits/stdc++.h>
using namespace std;
const long long PR = 1000000009;
int main() {
  ios::sync_with_stdio(false);
  int c1[21][21], c2[21][21], mask[21][21];
  int n, m;
  cin >> n >> m;
  char A[30][30];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c1[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      c2[i][j] = mask[i][j] = 0;
      int max1 = 0, sum1 = 0;
      for (int k = 0; k < n; ++k) {
        if (A[i][j] == A[k][j]) {
          sum1 += c1[k][j];
          max1 = max(max1, c1[k][j]);
          mask[i][j] |= (1 << k);
        }
      }
      c2[i][j] = sum1 - max1;
    }
  }
  int ans[1 << 20];
  for (int i = 0; i < (1 << 20); ++i) ans[i] = 1e9 + 9;
  ans[0] = 0;
  for (int i = 1; i < (1 << n); ++i) {
    int lsone = i & (-i), pl = 0;
    while (lsone >> pl + 1) pl++;
    for (int j = 0; j < m; ++j) {
      ans[i] = min(ans[i], ans[i ^ lsone] + c1[pl][j]);
      ans[i] = min(ans[i], ans[i & (i ^ mask[pl][j])] + c2[pl][j]);
    }
  }
  cout << ans[(1 << n) - 1] << '\n';
  return 0;
};
