#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int vis[200005];
int comp_size;
int cycle_length;
void dfs(int cur, int prev, int t, vector<vector<int>> &edges) {
  vis[cur] = t;
  comp_size++;
  for (int e : edges[cur]) {
    if (vis[e] == -1) {
      dfs(e, cur, t + 1, edges);
    } else if (e != prev) {
      if (cycle_length == 0) cycle_length = t - vis[e] + 1;
    }
  }
}
long long mod_exp(int a, int b) {
  if (b == 0) {
    return 1;
  } else if (b == 1) {
    return a;
  }
  long long c;
  if (b % 2 == 0) {
    c = mod_exp(a, b / 2);
    c = c * c % MOD;
  } else {
    c = mod_exp(a, (b - 1) / 2);
    c = c * c * a % MOD;
  }
  return c;
}
int main() {
  int n;
  memset(vis, -1, sizeof vis);
  cin >> n;
  vector<vector<int>> edges(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    edges[i].push_back(a);
    edges[a].push_back(i);
  }
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    if (vis[i] == -1) {
      comp_size = 0;
      cycle_length = 0;
      dfs(i, -1, 1, edges);
      cycle_length = cycle_length == 0 ? 2 : cycle_length;
      ans = (ans * mod_exp(2, comp_size - cycle_length) % MOD) *
            (mod_exp(2, cycle_length) - 2) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
