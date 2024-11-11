#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
long long n, c[2005], dp[2005], ans[2005], pos = 0;
vector<long long> v[2005];
void dfs1(long long nod) {
  for (auto it : v[nod]) {
    dfs1(it);
    dp[nod] += dp[it] + 1;
  }
}
void dfs2(long long node) {
  for (auto it : v[node]) {
    dfs2(it);
  }
  if (c[node] == dp[node]) {
    ans[node] = ++pos;
  } else {
    ans[node] = pos - (dp[node] - c[node]) + 1;
    pos++;
    for (long long i = 1; i <= n; i++) {
      if (dp[i] >= dp[node] && i != node) {
        ans[i]++;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long root = -1;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x >> c[i];
    if (x) {
      v[x].push_back(i);
    } else
      root = i;
  }
  dfs1(root);
  for (long long i = 1; i <= n; i++) {
    if (dp[i] < c[i]) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  dfs2(root);
  cout << "YES" << '\n';
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
}
