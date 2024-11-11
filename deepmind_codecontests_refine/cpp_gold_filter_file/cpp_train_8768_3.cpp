#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
const int MAXN = 2e5 + 5;
int n, k;
int hap[MAXN];
vector<int> adj[MAXN];
int cmp(int a, int b) { return a > b; }
int dfs(int u, int p, int d) {
  int s = 1;
  for (const int& v : adj[u]) {
    if (v == p) {
      continue;
    }
    s += dfs(v, u, d + 1);
  }
  hap[u] = s - d;
  return s;
}
int main() {
  setIO();
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0, 1);
  nth_element(hap + 1, hap + n - k, hap + n + 1, cmp);
  ll ans = 0;
  for (int i = 1; i <= n - k; i++) {
    ans += hap[i];
  }
  cout << ans << '\n';
}
