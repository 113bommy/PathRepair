#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int par[20][N + 1], lvl[N + 1], val[N + 1];
int arr[N + 1];
int dist[N + 1];
vector<pair<int, int> > adj[N + 1];
void dfs(int s, int p) {
  par[0][s] = p;
  for (auto nbr : adj[s]) {
    if (nbr.first != p) {
      lvl[nbr.first] = lvl[s] + 1;
      dist[nbr.first] = dist[s] + nbr.second;
      dfs(nbr.first, s);
    }
  }
}
void dfs2(int s, int p) {
  for (auto nbr : adj[s]) {
    if (nbr.first != p) {
      dfs2(nbr.first, s);
      val[s] += val[nbr.first];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 2; i <= n; i++) {
    int u, w;
    cin >> u >> w;
    adj[u].push_back({i, w});
    adj[i].push_back({u, w});
  }
  adj[0].push_back({1, 1});
  dfs(0, -1);
  for (int d = 1; d < 20; d++) {
    for (int i = 0; i <= n; i++) {
      int mid = par[d - 1][i];
      if (mid == -1)
        par[d][i] = -1;
      else
        par[d][i] = par[d - 1][mid];
    }
  }
  for (int i = 1; i <= n; i++) {
    int curr = i;
    for (int j = 19; j >= 0; j--) {
      if (par[j][curr] != -1 && arr[i] >= dist[i] - dist[par[j][curr]]) {
        curr = par[j][curr];
      }
    }
    if (!curr) curr = 1;
    val[par[0][i]]++;
    val[par[0][curr]]--;
  }
  dfs2(0, -1);
  for (int i = 1; i <= n; i++) cout << val[i] << ' ';
  return 0;
}
