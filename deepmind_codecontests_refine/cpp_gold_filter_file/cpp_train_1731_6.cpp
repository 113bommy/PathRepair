#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int N, M;
bool choose[maxn];
int lab[maxn];
void Init(void) {
  fill(begin(lab), end(lab), -1);
  fill(begin(choose), end(choose), 1);
}
int finds(int u) {
  if (lab[u] < 0) return u;
  return lab[u] = finds(lab[u]);
}
bool merges(int u, int v) {
  u = finds(u);
  v = finds(v);
  if (u == v) {
    if (choose[u] == 1) {
      choose[u] = 0;
      return 1;
    }
    return 0;
  }
  if (choose[u] == 0 && choose[v] == 0) return 0;
  if (lab[v] < lab[u]) swap(u, v);
  lab[u] += lab[v];
  lab[v] = u;
  choose[u] = (choose[v] && choose[u]);
  return 1;
}
struct edge_list {
  int u, v, w;
  bool operator<(const edge_list& other) const { return w > other.w; }
} edge[maxn];
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= M; ++i) cin >> edge[i].u >> edge[i].v >> edge[i].w;
  sort(edge + 1, edge + 1 + M);
  long long ans = 0;
  Init();
  for (int i = 1; i <= M; ++i) {
    if (merges(edge[i].u, edge[i].v)) {
      ans += edge[i].w;
    }
  }
  cout << ans << '\n';
}
