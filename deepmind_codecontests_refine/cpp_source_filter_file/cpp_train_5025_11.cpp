#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long n, a, b, da, db, mark[MAXN], markb[MAXN], h[MAXN];
vector<long long> adj[MAXN];
bool d;
long long dfs(long long v) {
  mark[v] = 1;
  long long m = 0, c;
  for (auto u : adj[v]) {
    if (!mark[u]) {
      c = dfs(u);
      if (c + m + 1 > 2 * da) {
        d = true;
      }
      m = max(m, c);
    }
  }
  return m + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++) {
      mark[i] = 0;
      markb[i] = 0;
      h[i] = 0;
      adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
      long long v, u;
      cin >> v >> u;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    if (db <= 2 * da) {
      cout << "Alice" << '\n';
      continue;
    }
    d = false;
    dfs(1);
    if (!d) {
      cout << "Alice" << '\n';
      continue;
    }
    queue<long long> q;
    q.push(a);
    h[a] = 0;
    bool p = false;
    while (!p) {
      long long v = q.front();
      q.pop();
      for (auto u : adj[v]) {
        if (!markb[u]) {
          h[u] = h[v] + 1;
          q.push(u);
          markb[u] = 1;
        }
        if (u == b) {
          p = true;
        }
      }
    }
    if (h[b] <= da) {
      cout << "Alice" << '\n';
      continue;
    }
    cout << "Bob" << '\n';
  }
}
