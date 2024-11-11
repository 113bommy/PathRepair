#include <bits/stdc++.h>
using namespace std;
const long long INF64 = (long long)(1e18) + 10;
long long n, dia = 0, dist = 0;
long long x, y, a, b, da, db;
vector<long long> g[100005];
vector<bool> vis(100005, false);
vector<long long> h(100005);
void dfs(long long x, long long d) {
  vis[x] = true;
  if (x == b) {
    dist = d;
    return;
  }
  for (auto i : g[x]) {
    if (!vis[i]) dfs(i, d + 1);
  }
}
void diameter(long long i) {
  vis[i] = true;
  pair<long long, long long> p = {0, 0};
  for (auto x : g[i]) {
    if (!vis[x]) {
      diameter(x);
      if (1 + h[x] > p.second) {
        p.second = h[x] + 1;
        if (p.second > p.first) swap(p.second, p.first);
      }
    }
  }
  h[i] = p.first;
  dia = max(dia, h[i] + p.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long q = 1, i, j, test;
  cin >> q;
  for (test = 1; test < (q + 1); test++) {
    cin >> n >> a >> b >> da >> db;
    dia = 0, dist = 0;
    for (i = 0; i < (n + 1); i++) {
      g[i].clear();
      vis[i] = false;
    }
    for (i = 0; i < (n - 1); i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(a, 0);
    fill(vis.begin(), vis.begin() + n + 1, false);
    diameter(a);
    if (dist <= da || dia <= 2 * da || 2 * da >= db)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
}
