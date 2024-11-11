#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007;
const long long INF = 999999999999999999;
const long long NN = (long long)(1e5 + 5);
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long max(long long x, long long y) {
  if (x > y) return x;
  return y;
}
long long power(long long x, unsigned long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long hcf(long long a, long long b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}
long long n, vertex, a, b, da, db, dist;
vector<long long> g[NN], vis(NN), d(NN);
void dfs(long long node, long long c = 0, long long parent = 0) {
  for (auto u : g[node])
    if (u != parent) dfs(u, c + 1, node);
  if (node == b) dist = c;
}
long long bfs(long long s) {
  queue<long long> q;
  q.push(s);
  vis[s]++;
  d[s] = 0;
  while (!q.empty()) {
    long long p = q.front();
    q.pop();
    for (auto u : g[p])
      if (!vis[u]) {
        vis[u]++;
        q.push(u);
        d[u] = d[p] + 1;
      }
  }
  long long i, mx = -INF, vertex;
  for (i = 1; i <= n; i++)
    if (d[i] > mx) {
      mx = d[i];
      vertex = i;
    }
  return mx;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long TT = 1;
  cin >> TT;
  while (TT--) {
    cin >> n >> a >> b >> da >> db;
    long long i, x, y;
    for (i = 0; i < n + 5; i++) g[i].clear(), vis[i] = 0, d[i] = 0;
    for (i = 1; i < n; i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dist = 0;
    dfs(a);
    if (dist <= da) {
      cout << "Alice\n";
      continue;
    }
    bfs(1);
    for (i = 0; i < n + 5; i++) vis[i] = 0;
    long long len = bfs(vertex);
    if (len <= 2 * da) {
      cout << "Alice\n";
      continue;
    }
    cout << (db > 2 * da ? "Bob" : "Alice") << "\n";
  }
}
