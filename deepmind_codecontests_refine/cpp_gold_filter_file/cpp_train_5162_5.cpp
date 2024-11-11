#include <bits/stdc++.h>
using namespace std;
struct data {
  long long int rem[6], ans, sub, newVal;
};
long long int n, k;
vector<long long int> g[200000 + 5];
data dp[200000 + 5];
data pre() {
  data r;
  int i;
  for (i = 0; i < 5; i++) r.rem[i] = 0;
  r.sub = 1;
  r.ans = 0;
  r.newVal = 0;
  return r;
}
data dfs(long long int u, long long int p) {
  long long int i, v, j, val, l, f = 0;
  data r, x;
  long long int rem[6];
  r = pre();
  x = pre();
  x.sub = 0;
  for (i = 0; i < (long long int)g[u].size(); i++) {
    v = g[u][i];
    if (v == p) continue;
    dp[v] = dfs(v, u);
    r.ans += dp[v].ans;
    r.sub += dp[v].sub;
    val = dp[v].newVal;
    val += dp[v].rem[0] + 1;
    for (j = 0; j < k; j++) rem[j] = dp[v].rem[j];
    for (j = 0; j < k; j++) dp[v].rem[(j + 1) % k] = rem[j];
    dp[v].rem[1 % k]++;
    for (j = 0; j < k; j++) x.rem[j] += dp[v].rem[j];
    dp[v].ans = val;
    r.ans += val;
    r.newVal += val;
    x.sub += dp[v].sub;
    x.ans += val;
  }
  for (i = 0; i < (long long int)g[u].size(); i++) {
    v = g[u][i];
    if (v == p) continue;
    x.ans -= dp[v].ans;
    x.sub -= dp[v].sub;
    for (j = 0; j < k; j++) x.rem[j] -= dp[v].rem[j];
    r.ans += dp[v].ans * x.sub;
    for (j = 1; j < k; j++)
      for (l = 1; l < k; l++)
        if ((j + l) <= k) f += dp[v].rem[j] * x.rem[l];
    x.ans += dp[v].ans;
    x.sub += dp[v].sub;
    for (j = 0; j < k; j++) {
      x.rem[j] += dp[v].rem[j];
      r.rem[j] += dp[v].rem[j];
    }
  }
  f /= 2;
  r.ans -= f;
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, u, v;
  cin >> n >> k;
  for (i = 1; i <= n; i++) dp[i] = pre();
  for (i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << dfs(1, 1).ans;
  return 0;
}
