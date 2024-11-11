#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[200005];
long long siz = 0;
long long cc = 0;
long long t, n;
long long a[200005];
long long vis[200005];
long long size_dict[200005];
void dfs(long long u) {
  vis[u] = cc;
  siz += 1;
  for (long long i = 0; i < adj[u].size(); i++) {
    if (!vis[adj[u][i]]) {
      dfs(adj[u][i]);
    }
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i <= 200004; i++) {
      adj[i].clear();
    }
    for (long long i = 0; i <= 200004; i++) vis[i] = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      adj[i + 1].push_back(a[i]);
      adj[a[i]].push_back(i + 1);
    }
    cc = 0;
    for (long long i = 0; i < n; i++) {
      if (!vis[i + 1]) {
        cc++;
        dfs(i + 1);
        size_dict[cc] = siz;
        siz = 0;
      }
    }
    for (long long i = 1; i <= n; i++) {
      cout << size_dict[vis[i]] << " ";
    }
    cout << "\n";
  }
}
