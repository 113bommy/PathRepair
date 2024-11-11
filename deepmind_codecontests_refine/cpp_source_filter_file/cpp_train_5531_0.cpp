#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  vector<set<long long> > adj(n);
  for (long long i = 0; i < n; ++i) adj[i].insert(i);
  for (long long o = 0; o < m; o++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  long long total = 0;
  for (long long i = 0; i < n; ++i) total += adj[i].size();
  if (total == ((n * n))) {
    cout << "NO";
    return 0;
  }
  long long u = 0, v = 1;
  for (long long i = 0; i < n; ++i) {
    if (adj[i].size() != n - 1) {
      std::vector<long long> v1(adj[i].begin(), adj[i].end());
      u = i;
      v = v1.size();
      for (long long j = 0; j < v1.size(); ++j) {
        if (v1[j] != j) {
          u = i;
          v = j;
          break;
        }
      }
      break;
    }
  }
  std::vector<long long> color(n);
  color[u] = 1;
  color[v] = 2;
  long long j = 3;
  std::vector<bool> vis(n, false);
  vis[u] = true;
  vis[v] = true;
  for (long long i = 0; i < n; ++i)
    if (!vis[i]) color[i] = j++;
  cout << "YES\n";
  for (long long i = 0; i < n; ++i) cout << color[i] << " ";
  cout << "\n";
  for (long long i = 0; i < n; ++i)
    cout << ((i != v) ? color[i] : color[u]) << " ";
}
