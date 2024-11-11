#include <bits/stdc++.h>
using namespace std;
long long a[100500], c[300], dp[100500][305], z, cnt, tmp, e, s, l, r, n, m, x,
    y, k, j, p, k1, k2, i, cur, rez;
vector<long long> f[100500];
long long Abs(long long x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  cin >> n >> m >> s >> e;
  for (i = 0; i < n; i++) cin >> a[i];
  for (j = 0; j < m; j++) {
    cin >> x;
    f[x].push_back(j);
  }
  for (i = 0; i <= n; i++)
    for (j = 0; j <= s / e; j++) dp[i][j] = n + 1;
  dp[0][0] = -1;
  for (i = 0; i < n; i++) {
    for (j = 0; j <= s / e; j++)
      if (dp[i][j] != n + 1) {
        long long tmp = upper_bound(f[a[i]].begin(), f[a[i]].end(), dp[i][j]) -
                        f[a[i]].begin();
        if (tmp != f[a[i]].size())
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], f[a[i]][tmp]);
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      }
  }
  rez = 0;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= s / e; j++) {
      if (i + dp[i][j] + 1 + j * e <= s && dp[i][j] != n + 1) rez = max(rez, j);
    }
  }
  cout << rez << endl;
  return 0;
}
