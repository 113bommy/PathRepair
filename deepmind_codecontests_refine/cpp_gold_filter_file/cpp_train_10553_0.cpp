#include <bits/stdc++.h>
using namespace std;
long long sum[3][3][2100010];
long long a[2000100], b[2001000];
char s[2000100];
long long cti(char x) {
  if (x == 'R') return 0;
  if (x == 'G') return 1;
  if (x == 'B') return 2;
}
signed main() {
  scanf("%s", s + 1);
  long long n = strlen(s + 1);
  for (long long i = 1; i <= n; ++i) a[i] = cti(s[i]);
  scanf("%s", s + 1);
  long long m = strlen(s + 1);
  for (long long i = 1; i <= m; ++i) b[i] = cti(s[i]);
  for (long long i = 0; i <= 2; ++i)
    for (long long j = 0; j <= 2; ++j) {
      for (long long k = 1; k <= m; ++k) {
        if (b[k - 1] == i && b[k] == j) sum[i][j][k] = 1;
        sum[i][j][k] += sum[i][j][k - 1];
      }
    }
  long long l = 1, r = 1;
  while (r < m && b[r] != a[1]) r++;
  long long ans = r - l + 1;
  for (long long i = 2; i <= n; ++i) {
    if (l <= m && a[i - 1] == b[l]) l++;
    if (l > m) break;
    if (r < m) {
      r++;
      while (r < m && b[r] != a[i]) r++;
    }
    ans += r - l + 1;
    if (a[i] != a[i - 1])
      ans -= sum[a[i]][a[i - 1]][r] - sum[a[i]][a[i - 1]][l - 1];
  }
  printf("%lld", ans);
}
