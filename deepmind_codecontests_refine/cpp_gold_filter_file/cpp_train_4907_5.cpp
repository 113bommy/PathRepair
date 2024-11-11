#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = 998244353;
const int MXN = (int)4e2 + 7;
inline long long add(long long v1, long long v2) {
  v1 += v2;
  if (v1 >= mod) v1 -= mod;
  if (v1 < 0) v1 += mod;
  return v1;
};
int a[MXN];
vector<pair<int, int> > qy[MXN][MXN];
int dp[MXN][MXN][2];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  long long ans = 0;
  while (m--) {
    int l, r, c, t;
    scanf("%d %d %d %d", &l, &r, &c, &t);
    t = min(t, r - l - 1);
    qy[t][l].push_back(make_pair(r, c));
  }
  int p1 = 0, p2 = 1;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) dp[i][j][0] = a[j] - a[i];
    for (pair<int, int> x : qy[0][i]) {
      ans = max(ans, dp[i][x.first][0] * 1ll * x.second);
    }
  }
  for (int i = 1; i < n; i++, swap(p1, p2)) {
    for (int l = 1; l < n; l++) {
      int p = l + i;
      for (int r = l + i + 1; r <= n; r++) {
        while (max(dp[l][p][p1], a[r] - a[p]) >=
               max(dp[l][p + 1][p1], a[r] - a[p + 1]))
          p++;
        dp[l][r][p2] = max(dp[l][p][p1], a[r] - a[p]);
      }
      for (pair<int, int> x : qy[i][l]) {
        ans = max(ans, dp[l][x.first][p2] * 1ll * x.second);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
