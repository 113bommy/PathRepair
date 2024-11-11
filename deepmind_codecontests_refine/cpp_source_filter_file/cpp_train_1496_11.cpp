#include <bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 10;
long long n, m, cnt, mark[N], ans[N];
vector<long long> nodes, adj[N], rev[N];
bool check = 1;
void dfs(long long v) {
  mark[v] = 1;
  for (long long u : adj[v])
    if (!mark[u]) dfs(u);
  nodes.push_back(v);
}
void sfd(long long v, long long c) {
  mark[v] = c;
  if (mark[v] == mark[v ^ 1]) check = 0;
  if (ans[v / 2] == -1) ans[v / 2] = !(v & 1);
  for (long long u : rev[v])
    if (mark[u] == -1) sfd(u, c);
}
void add(long long v, long long u) {
  adj[v].push_back(u);
  rev[u].push_back(v);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long v, u, c;
    cin >> v >> u >> c;
    v--;
    u--;
    if (!c) {
      add(2 * v, 2 * u ^ 1);
      add(2 * v + 1, 2 * u);
      add(2 * u, 2 * v + 1);
      add(2 * u + 1, 2 * v);
    } else {
      add(2 * v, 2 * u);
      add(2 * v + 1, 2 * u + 1);
      add(2 * u + 1, 2 * v + 1);
      add(2 * u, 2 * v);
    }
  }
  for (long long i = 0; i < 2 * n; i++)
    if (!mark[i]) dfs(i);
  memset(mark, -1, sizeof mark);
  memset(ans, -1, sizeof ans);
  while (nodes.size()) {
    long long v = nodes.back();
    nodes.pop_back();
    if (mark[v] != -1) continue;
    sfd(v, cnt++);
  }
  if (!check) return cout << "Impossible", 0;
  vector<long long> vec;
  for (long long i = 0; i < n; i++)
    if (ans[i]) vec.push_back(i);
  cout << vec.size() << '\n';
  for (long long i : vec) cout << i + 1 << ' ';
}
