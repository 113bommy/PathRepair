#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<long long>> adj(n + 1);
    for (long long i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    queue<long long> q;
    q.push(a);
    vector<long long> vis(n + 1);
    vis[a] = 1;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      for (auto x : adj[u])
        if (!vis[x]) vis[x] = vis[u] + 1, q.push(x);
    }
    if (vis[b] - vis[a] <= da) {
      cout << "Alice\n";
      continue;
    }
    long long root = 0, mx = -1;
    for (long long i = 1; i <= n; i++) {
      if (vis[i] > mx) mx = vis[i], root = i;
    }
    q.push(root);
    vis = vector<long long>(n + 1);
    vis[root] = 1;
    while (!q.empty()) {
      long long u = q.front();
      q.pop();
      for (auto x : adj[u])
        if (!vis[x]) vis[x] = vis[u] + 1, q.push(x);
    }
    mx = *max_element(vis.begin(), vis.end()) - 1;
    if (2 * da >= mx)
      cout << "Alice\n";
    else if (db > 2 * da)
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
}
