#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long sum, sol;
int v[200005], niv[200005];
long long dp[200005], sp[200005];
vector<int> g[200005];
void dfs(int nod, int tata) {
  niv[nod] = niv[tata] + 1;
  dp[1] += niv[nod] * v[nod];
  sp[nod] = v[nod];
  for (auto i : g[nod]) {
    if (i != tata) {
      dfs(i, nod);
      sp[nod] += sp[i];
    }
  }
}
void dfs2(int nod, int tata) {
  if (nod > 1) {
    dp[nod] = dp[tata] + sum - 2 * sp[nod];
    sol = max(sol, dp[nod]);
  }
  for (auto i : g[nod]) {
    if (i != tata) dfs2(i, nod);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  niv[0] = -1;
  dfs(1, 0);
  sol = max(sol, dp[1]);
  dfs2(1, 0);
  cout << sol;
  return 0;
}
