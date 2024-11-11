#include <bits/stdc++.h>
using namespace std;
int const N = 111;
char a[] = "hello", b[N];
int dp[N][N];
int cdp(int i, int j) {
  if (a[i] == '\0' || b[i] == '\0') {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int p = 0;
  if (a[i] == b[j]) {
    p = 1 + cdp(i + 1, j + 1);
  } else {
    p = max(cdp(i + 1, j), cdp(i, j + 1));
  }
  return dp[i][j] = p;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%s", b);
  printf("%s", cdp(0, 0) == 5 ? "YES" : "NO");
  return 0;
}
