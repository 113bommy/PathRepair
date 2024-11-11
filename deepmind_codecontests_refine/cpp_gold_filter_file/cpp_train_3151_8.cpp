#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
long long a[mxn];
int b[mxn];
long long sub[mxn];
vector<int> adj[mxn];
long long ans = 0;
vector<int> order;
void dfs(int u) {
  sub[u] = a[u];
  for (auto v : adj[u]) {
    dfs(v);
    sub[u] += max(0LL, sub[v]);
  }
  ans += sub[u];
}
void solve(int u) {
  for (auto v : adj[u]) {
    if (sub[v] > 0) solve(v);
  }
  order.push_back(u);
  for (int v : adj[u]) {
    if (sub[v] <= 0) solve(v);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (b[i] == -1) continue;
    adj[b[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == -1) {
      dfs(i);
      solve(i);
    }
  }
  cout << ans << '\n';
  for (int i : order) cout << i << ' ';
  cout << '\n';
  return 0;
}
