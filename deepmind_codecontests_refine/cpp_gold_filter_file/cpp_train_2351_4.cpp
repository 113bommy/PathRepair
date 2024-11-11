#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[150001];
vector<long long> vis(150001, 0);
vector<long long> vv;
long long cc;
void dfs(long long v, long long &cc, long long &ce) {
  vis[v] = 1;
  ce += adj[v].size();
  cc++;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      dfs(i, cc, ce);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long f = 1;
    long long i;
    for (i = 0; i < m; i++) {
      long long x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for (i = 1; i <= n; i++) {
      if (!vis[i]) {
        long long cc = 0;
        long long ce = 0;
        dfs(i, cc, ce);
        if (ce != (long long)(cc * (cc - 1))) {
          f = 0;
          break;
        }
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
