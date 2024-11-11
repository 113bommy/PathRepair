#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1, mod) % mod;
}
vector<int> adj[1000];
void dfs(int v, bool vis[]) {
  vis[v] = true;
  for (int w : adj[v])
    if (!vis[w]) dfs(w, vis);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  int p[n];
  for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= n - 1; j++)
      if (i + arr[i] == j || j - arr[j] == i)
        adj[i].push_back(j), adj[j].push_back(i);
  bool vis[n];
  for (int i = 0; i < n; i++) {
    memset(vis, false, sizeof(vis));
    dfs(i, vis);
    if (!vis[p[i]]) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
  return 0;
}
