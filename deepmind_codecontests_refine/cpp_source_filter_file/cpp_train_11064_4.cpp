#include <bits/stdc++.h>
using namespace std;
const int N = 155, M = N * N;
using ll = long long;
int n, m, a[N][N];
struct Edge {
  int v, nxt;
  ll w, cw;
} e[M << 2];
int head[M], ptr;
void add_edge(int uu, int vv) {
  e[ptr] = {vv, head[uu], 1, 0};
  head[uu] = ptr++;
  e[ptr] = {uu, head[vv], 1, 0};
  head[vv] = ptr++;
}
int ss[M], tt[M];
bool vis[M];
bool push(int pos, int fl) {
  if (tt[pos] && fl == 1) return 1;
  if (ss[pos] && fl == -1) return 1;
  vis[pos] = 1;
  for (int i = head[pos]; i != -1; i = e[i].nxt) {
    int v = e[i].v;
    if (fl == 1 && e[i].cw == 1) continue;
    if (fl == -1 && e[i].cw != -1) continue;
    if (vis[v]) continue;
    if (push(v, fl)) {
      ++e[i].cw;
      --e[i ^ 1].cw;
      return 1;
    }
  }
  return 0;
}
inline int id(int x, int y) { return (x - 1) * m + y; }
vector<pair<int, int>> v;
int main() {
  scanf("%d", &n);
  m = n;
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == -1) continue;
      if (i + 1 <= n && a[i + 1][j] >= 0) add_edge(id(i, j), id(i + 1, j));
      if (j + 1 <= m && a[i][j + 1] >= 0) add_edge(id(i, j), id(i, j + 1));
      if (a[i][j] > 0) {
        tt[id(i, j)] = 1;
        v.push_back({a[i][j], id(i, j)});
      }
    }
  sort(v.begin(), v.end());
  int flow = 0;
  ll ans = 0;
  for (int i = 0; i < int(v.size()) - 1; i++) {
    int pos = v[i].second;
    memset(vis, 0, sizeof(vis));
    while (push(pos, -1)) --flow, memset(vis, 0, sizeof(vis));
    tt[pos] = 0;
    ss[pos] = 1;
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j <= i; j++)
      if (!vis[v[j].second])
        while (push(v[j].second, 1)) ++flow, memset(vis, 0, sizeof(vis));
    ans += ll(v[i + 1].first - v[i].first) * flow;
  }
  cout << ans << endl;
  return 0;
}
