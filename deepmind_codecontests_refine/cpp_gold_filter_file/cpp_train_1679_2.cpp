#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const long long inf = 1e12;
int fa[N][20], n, a[N], vl[N][20], rt, _lg[N];
vector<int> v[N];
long long ans;
int calc(int d) { return (1 << _lg[d]) == d ? _lg[d] : _lg[d] + 1; }
void dfs(int x, int _fa, int nd) {
  int l = v[x].size(), y;
  if (x != rt) {
    long long tv = 1ll * (calc(nd) + 1) * a[rt];
    fa[x][0] = _fa;
    ans += a[x];
    for (register int i = (1); i <= (19); ++i)
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (register int i = (0); i <= (19); ++i)
      if (fa[x][i]) tv = min(tv, 1ll * (i + 1) * a[fa[x][i]]);
    ans += tv;
  }
  for (register int i = (0); i <= (l - 1); ++i) {
    y = v[x][i];
    if (y == _fa) continue;
    dfs(y, x, nd + 1);
  }
}
signed main() {
  memset(vl, 0x3f, sizeof(vl));
  ios::sync_with_stdio(false);
  cin.tie(0);
  _lg[1] = 0;
  cin >> n;
  rt = 1;
  for (register int i = (2); i <= (n); ++i) _lg[i] = _lg[i >> 1] + 1;
  for (register int i = (1); i <= (n); ++i) {
    cin >> a[i];
    if (a[rt] > a[i]) rt = i;
  }
  int x, y;
  for (register int i = (1); i <= (n - 1); ++i) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(rt, 0, 0);
  cout << ans << '\n';
  return 0;
}
