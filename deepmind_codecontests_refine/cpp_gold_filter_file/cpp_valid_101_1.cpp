#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
const int inf = 1e6;
int T;
int n, m, k;
int x[maxn], y[maxn];
int cntx[maxn], cnty[maxn];
map<pair<int, int>, int> prex, prey;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    prex.clear();
    prey.clear();
    memset(cntx, 0, sizeof(cntx));
    memset(cnty, 0, sizeof(cnty));
    long long ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> y[i];
    x[n + 1] = y[m + 1] = inf;
    while (k--) {
      int u, v;
      cin >> u >> v;
      int ex = lower_bound(x + 1, x + 1 + n + 1, u) - x;
      int ey = lower_bound(y + 1, y + 1 + m + 1, v) - y;
      if (u == x[ex]) {
        if (v == y[ey]) continue;
        ans += cnty[ey]++ - prex[{ex, ey}]++;
      } else
        ans += cntx[ex]++ - prey[{ex, ey}]++;
    }
    cout << ans << endl;
  }
  return 0;
}
