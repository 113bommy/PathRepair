#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = numeric_limits<int>::max();
const int N = 21;
int memo[1 << 21], cost[21][21];
bool vis[1 << 21];
int cost0[1 << 21], cnt[1 << 21], m;
int dp(int mask) {
  int n = __builtin_popcount(mask);
  if (n == m) return 0;
  if (vis[mask]) return memo[mask];
  vis[mask] = true;
  int ans = inf;
  for (int i = 0; i < m; i++)
    if (!(mask & (1 << i))) {
      ans = min(ans, cost0[mask | (1 << i)] + dp(mask | (1 << i)));
    }
  return memo[mask] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n >> m;
  vector<char> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n - 1; i++)
    cost[s[i] - 'a'][s[i + 1] - 'a']++, cost[s[i + 1] - 'a'][s[i] - 'a']++;
  for (int j = 0; j < (1 << m); j++)
    for (int k = 0; k < m; k++)
      for (int i = 0; i < m; i++)
        if ((j & (1 << k)) && !(j & (1 << i))) cost0[j] += cost[k][i];
  cout << dp(0) << endl;
}
