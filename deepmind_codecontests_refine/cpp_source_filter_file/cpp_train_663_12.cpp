#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7, M = 3e3 + 10;
const double PI = 3.1415926535;
int cnt[N];
int dp[M][M];
char str[N], f[N], s[N];
pair<int, int> dfs(int l, int r, int c) {
  if (l == r) return {l, r};
  if (dp[l][r] == c && str[l] == str[r]) return {l, r};
  if (dp[l + 1][r] == c)
    return dfs(l + 1, r, c);
  else
    return dfs(l, r - 1, c);
}
int main() {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  for (int i = 1; i <= n; i++) {
    cnt[str[i] - 'a']++;
    if (cnt[str[i] - 'a'] >= 100) {
      for (int j = 1; j <= 100; j++) printf("%c", str[i]);
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) dp[i][i] = 1;
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = len + l - 1;
      if (str[l] == str[r])
        dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
      else
        dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
    }
  }
  int l = 1, r = n, idx = 0;
  while (true) {
    if (dp[l][r] == 1) {
      f[idx++] = str[l];
      break;
    }
    pair<int, int> t = dfs(l, r, dp[l][r]);
    l = t.first + 1, r = t.second - 1;
    f[idx] = str[t.first], s[idx++] = str[t.first];
    if (l > r) break;
  }
  int d = min(50, idx - 1);
  for (int i = 0; i <= d; i++) printf("%c", f[i]);
  if ((dp[l][r] & 1) && dp[l][r] < 100) d--;
  for (int i = d; i >= 0; i--) printf("%c", s[i]);
  return 0;
}
