#include <bits/stdc++.h>
using namespace std;
long long int n, l[605], r[605];
long long int dp[605][605];
long long int dp1[605];
char b[1205];
bool rec(long long int i, long long int j) {
  if (j == 0) return 1;
  if (i > n) return (j == 0);
  if (dp[i][j] != -1) return dp[i][j];
  bool an = 0;
  for (int h = l[i]; h < min(r[i] + 1, j * 2); h++) {
    if (h % 2) {
      an = (rec(i + 1, (h - 1) / 2) &
            rec(i + 1 + (h - 1) / 2, n - i - (h - 1) / 2));
      if (an) {
        dp1[i] = h;
        break;
      }
    }
  }
  return dp[i][j] = an;
}
int main() {
  memset(dp, -1, sizeof dp);
  memset(b, '-', sizeof b);
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &l[i]), scanf("%lld", &r[i]);
  bool z = (rec(1, n));
  if (!z) return printf("IMPOSSIBLE\n"), 0;
  long long int i = 1, j = 1;
  while (j <= n) {
    while (b[i] != '-') i++;
    b[i] = '(';
    b[i + dp1[j]] = ')';
    j++;
  }
  for (int i = 1; i <= n * 2; i++) printf("%c", b[i]);
  printf("\n");
  return 0;
}
