#include <bits/stdc++.h>
using namespace std;
int const N = 1111;
char h[] = "hello";
int dp[N][6];
char s[N];
int cdp(int i, int j) {
  if (h[i] == '\0' || s[j] == '\0') {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int ans = 0;
  if (h[i] == s[j]) {
    ans = 1 + cdp(i + 1, j + 1);
  } else {
    int ans1 = cdp(i + 1, j);
    int ans2 = cdp(i, j + 1);
    ans = max(ans1, ans2);
  }
  return dp[i][j] = ans;
}
int main() {
  scanf("%s", s);
  memset(dp, -1, sizeof(dp));
  printf("%s", cdp(0, 0) == 5 ? "YES" : "NO");
  return 0;
}
