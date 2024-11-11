#include <bits/stdc++.h>
using namespace std;
const int maxx = 2e3 + 20, mod = 1e9 + 7;
vector<int> adj[maxx];
int n, d, ans[maxx], z[maxx], a[maxx], sum = 0;
bool vis[maxx];
void dfs(int root, int ROOT) {
  vis[root] = true;
  if (a[root] > a[ROOT] || a[ROOT] - a[root] > d ||
      (a[ROOT] - a[root] == 0 && root < ROOT))
    z[root] = 0;
  else {
    int e = 1;
    for (int x : adj[root]) {
      if (!vis[x]) {
        dfs(x, ROOT);
        e = (e * (z[x] + 1)) % mod;
      }
    }
    z[root] = e;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> d >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    fill(z, z + maxx, -1);
    fill(vis, vis + maxx, false);
    dfs(i, i);
    ans[i] = z[i];
    sum = (sum + ans[i]) % mod;
  }
  cout << sum << endl;
  return 0;
}
