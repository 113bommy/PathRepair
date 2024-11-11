#include <bits/stdc++.h>
using namespace std;
const int N = 2000 * 100 + 17;
vector<long long> adj[N];
long long t, n, m, a, b;
bool mark[N], vis[N];
void dfs1(int st, int p) {
  mark[st] = true;
  for (auto v : adj[st])
    if (mark[v] == false && v != p) dfs1(v, p);
}
void dfs2(int st, int p) {
  vis[st] = true;
  for (auto v : adj[st])
    if (vis[v] == false && v != p) dfs2(v, p);
}
long long solve() {
  long long res = 0;
  for (int i = 1; i <= n; i++)
    if (mark[i]) res++;
  return n - res - 1;
}
long long sov() {
  long long res = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i]) res++;
  return n - res - 1;
}
void cl() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    mark[i] = false;
    vis[i] = false;
  }
}
void input() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b;
    long long x, y;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs1(a, b);
    dfs2(b, a);
    x = sov(), y = solve();
    cout << x * y << endl;
    cl();
  }
}
int main() {
  input();
  return 0;
}
