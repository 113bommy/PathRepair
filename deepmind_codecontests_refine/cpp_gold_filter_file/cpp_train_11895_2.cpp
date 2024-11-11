#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int l[10000], r[10000];
int mat[100][100];
int nitv = 0;
int n, m;
int get(int v, int s, int e) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (l[mat[i][v]] >= s && r[mat[i][v]] <= e) {
      ++ret;
    }
  }
  return ret * ret;
}
int main(int argc, char** argv) {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> l[nitv] >> r[nitv];
      --l[nitv], --r[nitv];
      for (int a = l[nitv]; a <= r[nitv]; ++a) {
        mat[i][a] = nitv;
      }
      ++nitv;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int s = 0; s + i - 1 < m; ++s) {
      int e = s + i - 1;
      for (int mid = s; mid <= e; ++mid) {
        dp[s][e] =
            max(dp[s][e], (mid == s ? 0 : dp[s][mid - 1]) +
                              (mid == e ? 0 : dp[mid + 1][e]) + get(mid, s, e));
      }
    }
  }
  cout << dp[0][m - 1] << endl;
  return 0;
}
