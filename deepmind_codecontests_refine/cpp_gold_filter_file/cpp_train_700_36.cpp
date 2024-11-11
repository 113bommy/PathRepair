#include <bits/stdc++.h>
using namespace std;
const int maxn = 57;
const int inf = (1LL << 29);
int a[maxn], b[maxn];
long double val[maxn];
long double dp[maxn][maxn];
long double sum[maxn];
bool cmp(long double a, long double b) { return a > b; }
long double s[57][maxn];
vector<long double> g[57];
int aa[maxn], now[maxn];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i], aa[i] = a[i];
  long double l = 0.0, r = 1e11;
  sort(aa + 1, aa + n + 1);
  int len = unique(aa + 1, aa + n + 1) - aa - 1;
  for (int i = 1; i <= n; i++)
    now[i] = lower_bound(aa + 1, aa + len + 1, a[i]) - aa;
  for (int i = 1; i <= 200; i++) {
    long double mid = (l + r) / 2;
    for (int k = 1; k <= len; k++) g[k].clear();
    for (int k = 1; k <= n; k++)
      val[k] = a[k] - b[k] * mid, g[now[k]].push_back(val[k]);
    for (int k = 1; k <= len; k++) sort(g[k].begin(), g[k].end(), cmp);
    for (int k = 1; k <= len; k++) {
      sum[k] = 0;
      for (int z = 0; z < g[k].size(); z++) sum[k] += g[k][z];
    }
    for (int k = 1; k <= len + 1; k++)
      for (int z = 0; z <= n + 1; z++) dp[k][z] = 1e11;
    dp[len + 1][0] = 0;
    for (int k = len; k; k--) {
      for (int z = 0; z <= n; z++) {
        double x = 0;
        int fi = 0;
        while (2 * fi + z - (int)g[k].size() < 0 ||
               fi < (int)(g[k].size()) - z) {
          if (fi) x += g[k][fi - 1];
          fi++;
        }
        for (int j = fi; z + 2 * j - (int)g[k].size() <= n && j <= g[k].size();
             j++) {
          if (j) x += g[k][j - 1];
          dp[k][z] = min(dp[k][z],
                         dp[k + 1][z + 2 * j - (int)g[k].size()] + sum[k] - x);
          if (k == 2 && z == 2) {
          }
        }
      }
    }
    long double ans = 1e11;
    for (int z = 0; z <= n; z++) ans = min(ans, dp[1][z]);
    if (ans < 0)
      r = mid;
    else
      l = mid;
  }
  long long a = ceil(l * 1000 - 0.00000001);
  printf("%lld", a);
  return 0;
}
