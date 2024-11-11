#include <bits/stdc++.h>
using namespace std;
const int mn = 210;
int n, i, j;
char s[mn];
bool t[mn];
long long ans, f[mn][2];
long long dp(int c) {
  fill(f[0], f[n + 1], 0);
  f[0][c] = 1;
  for (i = 0; i <= n - 1; ++i)
    if (!t[i + 1])
      f[i + 1][0] = f[i][0];
    else {
      if (t[i])
        f[i + 1][1] = f[i][0] + f[i][1];
      else {
        f[i + 1][0] = f[i - 1][0] + f[i - 1][1];
        f[i + 1][1] = f[i][0] + f[i][1];
      }
    }
  return f[n][c];
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (i = 1; i <= n; ++i) s[i + n] = s[i];
  for (i = 1; i <= n; ++i)
    if (s[i] == 'B') {
      j = i;
      break;
    }
  if (j == 0) {
    puts("1");
    return 0;
  }
  for (i = 1; i <= n; ++i) t[i] = s[i + j - 1] == 'A';
  ans = dp(0) + dp(1);
  printf("%I64d\n", ans);
  return 0;
}
