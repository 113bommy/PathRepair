#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<int> ind[N];
vector<int> adj[N];
int a[N], cnt[N];
bool good[N], vis[N];
long long ans[N];
vector<int> factors(int x) {
  vector<int> ans;
  for (int j = 1; j * j <= x; j++)
    if (x % j == 0) {
      ans.push_back(j);
      if (x / j != j) ans.push_back(x / j);
    }
  return ans;
}
int dfs(int u) {
  int ans = 1;
  vis[u] = 1;
  for (auto v : adj[u])
    if (good[v] && !vis[v]) ans += dfs(v);
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (auto d : factors(a[i])) ind[d].push_back(i);
    cnt[a[i]]++;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i < N; i++) {
    for (auto v : ind[i]) good[v] = true, vis[v] = false;
    for (auto v : ind[i])
      if (!vis[v]) {
        int cnt = dfs(v);
        ans[i] += 1LL * cnt * cnt;
      }
    for (auto v : ind[i]) good[v] = false;
  }
  for (int i = N - 1; i > 0; i--)
    for (int j = 2 * i; j < N; j += i) ans[i] -= ans[j];
  for (int i = 1; i < 100; i++) {
    ans[i] += cnt[i];
    ans[i] /= 2;
  }
  for (int i = 1; i < N; i++)
    if (ans[i]) cout << i << " " << ans[i] << "\n";
}
