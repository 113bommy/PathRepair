#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int vis[100005];
long long m = 1000000007, cnt = 0;
void dfs(int s) {
  vis[s] = 1;
  for (int i = 0; i < adj[s].size(); i++) {
    if (!vis[adj[s][i]]) {
      cnt++;
      dfs(adj[s][i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (!c) {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  long long ans = 0, nk = n;
  for (int i = 1; i <= n; i++) {
    long long cntK;
    cnt = 1;
    if (!vis[i]) {
      dfs(i);
      cntK = cnt;
      for (int i = 2; i <= k; i++) {
        cntK *= cnt;
        cntK %= m;
      }
      ans = (ans + cntK) % m;
      ans %= m;
    }
  }
  for (int i = 2; i <= k; i++) {
    nk *= n;
    nk %= m;
  }
  nk %= m;
  cout << (nk - ans + m) % m;
  return 0;
}
