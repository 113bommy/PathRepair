#include <bits/stdc++.h>
using namespace std;
map<pair<int, long long>, int> dp;
map<pair<int, long long>, bool> visit;
int dfs(int x, long long S) {
  S = S & ((1LL << x) - 1);
  if (x == 0) return 0;
  if (visit[{x, S}]) return dp[{x, S}];
  vector<bool> f(63, 0);
  for (int i = x; i >= 1; i--) {
    long long Si = 1 << (i - 1);
    if (S & Si) continue;
    f[dfs(x - i, S | Si)] = 1;
  }
  for (int i = 0; i < 63; i++)
    if (!f[i]) {
      visit[{x, S}] = true;
      return dp[{x, S}] = i;
    }
}
int main() {
  int n, x;
  cin >> n;
  for (int i = 60; i >= 0; i--) dfs(i, 0);
  int SG = 0;
  for (int i = 0; i < n; i++) scanf("%d", &x), SG ^= dp[{x, 0}];
  if (SG)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
