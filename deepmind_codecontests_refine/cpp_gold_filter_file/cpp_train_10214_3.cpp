#include <bits/stdc++.h>
using namespace std;
void dfs(long long u, long long par, vector<vector<long long>> &adj,
         long long status[], long long &cc, long long &dd) {
  if (status[u] == 1) {
    if (cc == 1)
      dd++;
    else
      cc = 1;
    return;
  }
  status[u] = 1;
  for (long long i = 0; i < adj[u].size(); i++) {
    if (adj[u][i] == par) continue;
    dfs(adj[u][i], u, adj, status, cc, dd);
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> adj(n);
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long cc = 0;
  long long dd = 0;
  long long ee = 0;
  long long status[n];
  memset(status, 0, sizeof(status));
  for (long long i = 0; i < n; i++) {
    if (status[i] == 0) {
      ee++;
      dfs(i, -1, adj, status, cc, dd);
    }
  }
  if (cc == 1 && dd <= 1 && ee == 1) {
    cout << "FHTAGN!" << endl;
  } else
    cout << "NO" << endl;
}
