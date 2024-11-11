#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int n, m, k;
struct DSU {
  stack<pair<int, int> > stk;
  int fa[maxn], siz[maxn];
  void init() {
    for (int i = 1; i <= n * 2 + 1; i++) {
      fa[i] = i;
      siz[i] = 1;
    }
  }
  int findset(int x) { return x == fa[x] ? x : findset(fa[x]); }
  bool Union(int x, int y) {
    int rx = findset(x), ry = findset(y);
    if (rx == ry) return false;
    if (siz[rx] > siz[ry]) swap(rx, ry);
    fa[rx] = ry;
    siz[ry] += siz[rx];
    stk.push({rx, ry});
    return true;
  }
  void undo() {
    pair<int, int> now = stk.top();
    fa[now.first] = now.first;
    siz[now.second] -= siz[now.first];
    stk.pop();
  }
} dsu;
int a[maxn], b[maxn], c[maxn];
int f[maxn];
vector<int> vec[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  dsu.init();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (c[a[i]] == c[b[i]]) {
      int rx = dsu.findset(a[i]);
      int ry = dsu.findset(b[i]);
      if (rx == ry)
        f[c[a[i]]] = 1;
      else {
        dsu.Union(a[i], b[i] + n);
        dsu.Union(b[i], a[i] + n);
      }
    }
  }
  map<pair<int, int>, int> mp;
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    if (c[a[i]] != c[b[i]] && !f[a[i]] && !f[b[i]]) {
      int r1 = c[a[i]], r2 = c[b[i]];
      if (r1 > r2) swap(r1, r2);
      if (!mp[{r1, r2}]) mp[{r1, r2}] = ++cnt;
      int pos = mp[{r1, r2}];
      vec[pos].push_back(i);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    int now = dsu.stk.size();
    for (int j = 0; j < vec[i].size(); j++) {
      int v = vec[i][j];
      int rx = dsu.findset(a[v]), ry = dsu.findset(b[v]);
      if (rx == ry) {
        ans--;
        break;
      }
      dsu.Union(a[v], b[v] + n);
      dsu.Union(b[v], a[v] + n);
    }
    while (dsu.stk.size() > now) {
      dsu.undo();
    }
  }
  cnt = 0;
  for (int i = 1; i <= k; i++) {
    if (!f[i]) cnt++;
  }
  ans += 1ll * cnt * (cnt - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
