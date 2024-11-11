#include <bits/stdc++.h>
using namespace std;
const long long N = 4e3 + 5;
long long a1, a2, a3, a4, n, m, la, lb;
long long prea[N][27], preb[N][27], pos[27], f[N][N];
char a[N], b[N];
signed main() {
  scanf("%lld%lld%lld%lld", &a1, &a2, &a3, &a4);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  n = strlen(a + 1);
  for (register long long i = 1; i <= n; ++i) {
    for (register long long j = 1; j <= 26; ++j) prea[i][j] = pos[j];
    pos[a[i] - 'a' + 1] = i;
  }
  memset(pos, 0, sizeof(pos));
  m = strlen(b + 1);
  for (register long long i = 1; i <= m; ++i) {
    for (register long long j = 1; j <= 26; ++j) preb[i][j] = pos[j];
    pos[b[i] - 'a' + 1] = i;
  }
  memset(f, 60, sizeof(f));
  f[0][0] = 0;
  for (register long long i = 0; i <= n; ++i)
    for (register long long j = 0; j <= m; ++j) {
      if (i) f[i][j] = min(f[i][j], f[i - 1][j] + a2);
      if (j) f[i][j] = min(f[i][j], f[i][j - 1] + a1);
      if (i && j) f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]) * a3);
      la = prea[i][b[j] - 'a' + 1];
      lb = preb[j][a[i] - 'a' + 1];
      if (i && j && la && lb)
        f[i][j] = min(f[i][j], f[la - 1][lb - 1] + a4 + a2 * (i - la - 1) +
                                   a1 * (j - lb - 1));
    }
  printf("%lld\n", f[n][m]);
  return 0;
}
