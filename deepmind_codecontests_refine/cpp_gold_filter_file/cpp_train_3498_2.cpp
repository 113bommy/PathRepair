#include <bits/stdc++.h>
using namespace std;
short f[8080][8080];
int dp[8080];
int dec(int p) {
  int r = 0;
  while (p) {
    r++, p /= 10;
  }
  return r;
}
int main() {
  int n;
  char s[8080];
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    f[i][i] = 0;
    for (int j = i + 1; j < n; j++) {
      int k = f[i][j - 1];
      while (k > 0 && s[j] != s[i + k]) k = f[i][i + k - 1];
      if (s[j] == s[i + k]) k++;
      f[i][j] = k;
    }
  }
  dp[0] = 2;
  for (int i = 1; i < n; i++) {
    dp[i] = 1 << 30;
    for (int j = 0; j <= i; j++) {
      int ff = f[j][i];
      int l = i - j + 1;
      int p = 1, t = l;
      if (!(l % (l - ff))) {
        p = l / (l - ff);
        t = l - ff;
      }
      dp[i] = min(dp[i], (j ? dp[j - 1] : 0) + dec(p) + t);
    }
  }
  printf("%d\n", dp[n - 1]);
  return 0;
}
