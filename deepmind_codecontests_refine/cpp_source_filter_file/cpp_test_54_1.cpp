#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
int t, n, m, tot, a, b;
string s;
bool ok = false;
int head[4 * maxn], vis[4 * maxn];
struct Edge {
  int to, next;
} edge[4 * maxn];
void add(int u, int v) {
  edge[++tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot;
}
void dfs(int k, int col) {
  vis[k] = col;
  if (k <= n) {
    if (col == 1)
      a++;
    else
      b++;
  }
  for (int i = head[k]; i != -1; i = edge[i].next) {
    if (vis[edge[i].to] == vis[k]) {
      ok = false;
      return;
    }
    if (vis[edge[i].to] != -1) continue;
    dfs(edge[i].to, 1 - col);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    tot = 0;
    int u, v;
    cin >> n >> m;
    for (int i = 0; i <= n + m + 1; i++)
      head[i] = -1, edge[i].next = -1, vis[i] = -1;
    int cnt = n;
    for (int i = 1; i <= m; i++) {
      cin >> u >> v >> s;
      if (s == "imposter") {
        add(u, v);
        add(v, u);
      } else {
        add(u, ++cnt);
        add(cnt, u);
        add(v, cnt);
        add(cnt, v);
      }
    }
    int ans = 0;
    ok = true;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == -1) {
        a = 0, b = 0;
        dfs(i, 0);
        ans += max(a, b);
      }
    }
    if (ok)
      cout << ans << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
