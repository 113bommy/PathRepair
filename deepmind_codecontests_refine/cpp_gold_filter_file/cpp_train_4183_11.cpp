#include <bits/stdc++.h>
using namespace std;
const int inf = 1000002013;
const double pi = atan(1.0) * 4.0;
const double eps = 1e-8;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
int bc(int n) { return n ? bc((n - 1) & n) + 1 : 0; }
const int N = 1001;
int i, j, k, m, n, h;
string s;
int x[N], y[N], V[N];
int g[N][N], d[N][N];
int attackx[N], attacka[N], attackd[N], defendx[N], defenda[N];
int rec(int i) {
  V[i] = 1;
  for (int j = 1; j <= n; j++)
    if (g[i][j]) {
      if (y[j] == 0 || (V[y[j]] == 0 && rec(y[j]))) {
        x[i] = j;
        y[j] = i;
        return 1;
      }
    }
  return 0;
}
int solve() {
  int ans = 0;
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  for (int i = 1; i <= m; i++)
    if (x[i] == 0) {
      for (j = 1; j <= m; j++) V[j] = 0;
      ans += rec(i);
    }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = (i != j) * inf;
  for (int i = 1; i <= m; i++) {
    cin >> j >> k;
    d[j][k] = d[k][j] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cin >> m >> n >> k >> h;
  for (int i = 1; i <= m; i++) cin >> attackx[i] >> attacka[i] >> attackd[i];
  for (int i = 1; i <= n; i++) cin >> defendx[i] >> defenda[i];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      if (attacka[i] < defenda[j]) continue;
      if (attackd[i] < d[attackx[i]][defendx[j]]) continue;
      g[i][j] = 1;
    }
  long long t = solve();
  long long ans = t * k;
  for (int bases = 1; bases <= m; bases++) {
    ans = min(ans, 1LL * bases * h + k * min(t, 1LL * m - bases));
  }
  cout << ans << endl;
  return 0;
}
