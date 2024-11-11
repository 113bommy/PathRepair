#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
vector<long long> vertex[maxn];
long long dist[maxn];
void dfs(long long v, long long d, long long p = -1) {
  dist[v] = d;
  for (long long i = 0; i < vertex[v].size(); i++) {
    if (vertex[v][i] != p) {
      dfs(vertex[v][i], d + 1, v);
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for (long long i = 1; i <= n; i++) {
      vertex[i].clear();
    }
    for (long long i = 0; i < (n - 1); i++) {
      long long v, u;
      cin >> v >> u;
      vertex[v].push_back(u);
      vertex[u].push_back(v);
    }
    dfs(a, 0);
    if (dist[b] <= da) {
      cout << "Alice" << endl;
      continue;
    }
    if (db <= 2 * da) {
      cout << "Alice" << endl;
      continue;
    }
    long long w = 0;
    for (long long i = 1; i <= n; i++) {
      if (vertex[i].size() == 1) {
        w = i;
        break;
      }
    }
    dfs(w, 0);
    long long k = -1, r = 0;
    for (long long i = 1; i <= n; i++) {
      if (k < dist[i]) {
        k = dist[i];
        r = i;
      }
    }
    dfs(r, 0);
    k = -1;
    for (long long i = 1; i <= n; i++) {
      k = max(k, dist[i]);
    }
    if (k <= 2 * da) {
      cout << "Alice" << endl;
      continue;
    }
    cout << "Bob" << endl;
  }
}
