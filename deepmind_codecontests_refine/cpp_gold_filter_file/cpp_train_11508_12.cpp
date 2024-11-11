#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, d, h, v, nd, nh, mx;
vector<long long> adj[N], e, e2;
void dfs(int u, int p, int dist) {
  if (dist > mx) mx = dist;
  for (int i = 0, v; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (v == p) continue;
    dfs(v, u, dist + 1);
  }
}
void solve() {
  cin >> n >> d >> h;
  v = 2;
  for (int i = 1; i <= h && v <= n; i++, v++) {
    e.push_back(v - 1);
    e2.push_back(v);
    adj[v - 1].push_back(v);
    adj[v].push_back(v - 1);
  }
  for (int i = 1, j = 1; i <= d - h && v <= n && j <= h; j++, i++, v++) {
    if (i == 1) {
      e.push_back(1);
      adj[1].push_back(v);
      adj[v].push_back(1);
    } else {
      e.push_back(v - 1);
      adj[v - 1].push_back(v);
      adj[v].push_back(v - 1);
    }
    e2.push_back(v);
  }
  for (; v <= n; v++) {
    e.push_back(h);
    e2.push_back(v);
    adj[h].push_back(v);
    adj[v].push_back(h);
  }
  mx = 0;
  dfs(1, -1, 0);
  nh = mx;
  mx = 0;
  dfs(1 + h, -1, 0);
  nd = mx;
  if (nh == h && nd == d && e.size() == n - 1) {
    for (int i = 0; i < e.size(); i++) cout << e[i] << " " << e2[i] << "\n";
  } else
    cout << "-1\n";
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
