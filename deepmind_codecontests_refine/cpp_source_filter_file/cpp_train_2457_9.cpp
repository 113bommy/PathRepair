#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
int rd() {
  int x = 0, f = 1;
  char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (c < 48) {
    if (c == '-') {
      f = -1;
    }
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (c > 47) {
    x = (((x << 2) + x) << 1) + (c ^ 48);
    c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  return x * f;
}
const int N = 5e3 + 5;
const int M = 1e5 + 5;
int n, ans;
int a[N], dp[N][N];
int binnum[N], binmod[N];
int main() {
  n = rd();
  for (int i = 1; i <= n; i++) {
    a[i] = rd();
  }
  for (int i = 0; i <= n; i++) {
    memset(binnum, 0, sizeof binnum);
    memset(binmod, 0, sizeof binmod);
    for (int j = 1; j < i; j++) {
      binnum[a[j]] = max(binnum[a[j]], dp[i][j]);
      binmod[a[j] % 7] = max(binmod[a[j] % 7], dp[i][j]);
    }
    for (int j = i + 1; j <= n; j++) {
      dp[i][j] = max(dp[i][j], dp[i][0] + 1);
      dp[i][j] = max(dp[i][j], binnum[a[j] - 1] + 1);
      dp[i][j] = max(dp[i][j], binnum[a[j] + 1] + 1);
      dp[i][j] = max(dp[i][j], binmod[a[j] % 7] + 1);
      dp[j][i] = dp[i][j];
      binnum[a[j]] = max(binnum[a[j]], dp[i][j]);
      binmod[a[j] % 7] = max(binmod[a[j] % 7], dp[i][j]);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
