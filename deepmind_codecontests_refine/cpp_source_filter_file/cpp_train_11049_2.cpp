#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 2;
long long sz[maxn], dp[maxn], dp2[maxn];
vector<pair<int, bool>> adj[maxn];
int n;
bool L(string s) {
  for (auto c : s) {
    if (c != '4' && c != '7') return false;
  }
  return true;
}
void getdp(int v, int p = -1) {
  sz[v] = 1;
  for (auto P : adj[v]) {
    int u = P.first;
    bool f = P.second;
    if (u != p) {
      getdp(u, v);
      if (f) {
        dp[v] += sz[u];
      } else {
        dp[v] += dp[u];
      }
      sz[v] += sz[u];
    }
  }
}
void getdp2(int v, int p = -1) {
  for (auto P : adj[v]) {
    int u = P.first;
    bool f = P.second;
    if (u != p) {
      if (f) {
        dp2[u] = n - sz[u];
      } else {
        dp2[u] = dp2[v] + dp[v] - dp[u];
      }
      getdp2(u, v);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    string s;
    cin >> v >> u >> s;
    v--;
    u--;
    bool f = L(s);
    adj[v].push_back({u, f});
    adj[u].push_back({v, f});
  }
  getdp(0);
  getdp2(0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i] * dp2[i];
    ans += dp[i] * (dp[i] - 1);
    ans += dp2[i] * (dp2[i] - 1);
  }
  cout << ans;
}
