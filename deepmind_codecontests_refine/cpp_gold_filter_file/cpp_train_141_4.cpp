#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1001;
int n, x, xlast, parent[MAXN];
bool dp[MAXN][MAXN];
vector<int> lasts, sz = {0};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a > 0)
      parent[a] = i;
    else
      lasts.emplace_back(i);
  }
  for (auto v : lasts) {
    int cnt = 0;
    bool addChain = true;
    for (; v > 0; v = parent[v]) {
      cnt++;
      if (v == x) xlast = cnt, addChain = false;
    }
    if (addChain) sz.emplace_back(cnt);
  }
  int m = sz.size();
  m--;
  for (int j = 0; j <= m; j++) {
    dp[0][j] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j - 1])
        dp[i][j] = true;
      else if (i >= sz[j] && dp[i - sz[j]][j - 1]) {
        dp[i][j] = true;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[i][m]) {
      cout << xlast + i << '\n';
    }
  }
  return 0;
}
