#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2000 + 3;
long long x[N], y[N], fa[N];
long long c[N], k[N];
int tot;
struct Edge {
  int u, v;
  long long w;
} edge[N * N + N];
vector<int> ans;
vector<pair<int, int>> ans2;
inline int Find(int u) { return (fa[u] == u ? u : fa[u] = Find(fa[u])); }
inline void addedge(int u, int v, long long w) {
  edge[++tot].u = u;
  edge[tot].v = v;
  edge[tot].w = w;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    addedge(0, i, c[i]);
  }
  for (int i = 1; i <= n; i++) cin >> k[i];
  for (int i = 0; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      addedge(
          i, j,
          1ll * (k[i] + k[j]) * (0ll + abs(x[i] - x[j]) + abs(y[i] - y[j])));
      addedge(
          j, i,
          1ll * (k[i] + k[j]) * (0ll + abs(x[i] - x[j]) + abs(y[i] - y[j])));
    }
  sort(edge + 1, edge + tot + 1, [](Edge u, Edge v) { return u.w < v.w; });
  long long len = 0;
  for (int i = 1; i <= tot; i++) {
    int u = edge[i].u, v = edge[i].v;
    long long w = edge[i].w;
    int fu = Find(u);
    int fv = Find(v);
    if (fu == fv) continue;
    if (u == 0)
      ans.push_back(v);
    else if (v == 0)
      ans.push_back(u);
    else
      ans2.push_back(make_pair(u, v));
    fa[fu] = fv;
    len += w;
  }
  cout << len << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
  cout << ans2.size() << endl;
  for (int i = 0; i < ans2.size(); i++)
    cout << ans2[i].first << ' ' << ans2[i].second << endl;
  return 0;
}
