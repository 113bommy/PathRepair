#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int>& a) { return (a.second < a.first); }
bool vis[100001];
vector<int> adj[100001];
int visTot = 0;
void dfs(int u) {
  vis[u] = 1;
  visTot++;
  for (int x : adj[u]) {
    if (!vis[x]) {
      dfs(x);
    }
  }
}
int main() {
  int n, k, x, y;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      cnt++;
    }
  }
  int no_satisf = k - (n - cnt);
  cout << no_satisf;
  return 0;
}
