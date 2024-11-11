#include <bits/stdc++.h>
using namespace std;
long long n, m, u, v, lon, luu;
long long check[200005];
vector<long long> adj[200005];
queue<long> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() > lon) {
      lon = adj[i].size();
      luu = i;
    }
  }
  q.push(luu);
  check[luu] = 1;
  while (q.size() > 0) {
    long p = q.front();
    q.pop();
    for (int i = 0; i < adj[p].size(); i++) {
      if (check[adj[p][i]] == 0) {
        cout << p << " " << adj[p][i] << endl;
        q.push(adj[p][i]);
        check[adj[p][i]] = 1;
      }
    }
  }
}
