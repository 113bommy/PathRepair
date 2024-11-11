#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int head[N], edge_id, cnt;
struct edge {
  int to, next;
} e[N << 1];
void add_edge(int u, int v) {
  ++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
int n, m;
bool vis[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, iE = m; i <= iE; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
  }
  for (int x = 1, xE = n; x <= xE; x++)
    if (!vis[x])
      for (int i = head[x]; i; i = e[i].next)
        if (e[i].to > i) vis[e[i].to] = 1;
  for (int x = n, xE = 1; x >= xE; x--)
    if (!vis[x])
      for (int i = head[x]; i; i = e[i].next) vis[e[i].to] = 1;
  for (int x = 1, xE = n; x <= xE; x++)
    if (!vis[x]) ++cnt;
  cout << cnt << "\n";
  for (int x = 1, xE = n; x <= xE; x++)
    if (!vis[x]) cout << x << " ";
  cout << "\n";
  return 0;
}
