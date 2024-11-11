#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int mod = 1e9 + 7;
const int N = 2e5 + 15;
long long n;
vector<long long> adj[N];
bool vis[N];
long long ans[N];
long long cnt = 0;
void dfs(int node) {
  vis[node] = true;
  cnt++;
  for (auto x : adj[node]) {
    if (!vis[x]) dfs(x);
  }
  ans[node] = cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n + 10; i++)
      adj[i].clear(), vis[i] = false, ans[i] = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      adj[i + 1].push_back(x);
    }
    for (long long i = 1; i <= n; i++) {
      if (!vis[i]) {
        cnt = 0;
        dfs(i);
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
