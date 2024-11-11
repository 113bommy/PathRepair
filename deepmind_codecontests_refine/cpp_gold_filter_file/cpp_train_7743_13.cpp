#include <bits/stdc++.h>
using namespace std;
int dp[400000];
int n, k;
char s[400000];
int len;
int Dp(int u) {
  if (dp[u] != -1) return dp[u];
  for (int i = u + 1; i <= u + k && i < n; i++) {
    if (s[i] == '.' && Dp(i)) return dp[u] = 1;
  }
  return dp[u] = 0;
}
int main() {
  cin >> n >> k;
  getchar();
  gets(s);
  len = strlen(s);
  memset(dp, -1, sizeof(dp));
  dp[len - 1] = 1;
  Dp(0);
  if (dp[0])
    cout << "YES\n";
  else
    cout << "NO\n";
}
