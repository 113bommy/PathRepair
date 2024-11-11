#include <bits/stdc++.h>
const int mo = 12345;
bool p[27][125], pp[27];
int bas[27], mu[27], f[125][125], g[125][125], ans[125], res[125];
int main() {
  long long n;
  int c, i, j, k, t, b, cnt = 0;
  char s[5];
  scanf("%I64d%d", &n, &c);
  memset((p), 0, sizeof(p)), memset((f), 0, sizeof(f));
  for (i = 0; i < 26; i++) mu[i] = 1, pp[i] = false;
  for (i = 0; i < c; i++) {
    scanf("%s%d", s, &b);
    mu[*s - 'A'] *= b;
    p[*s - 'A'][b] = pp[*s - 'A'] = true;
  }
  for (bas[i = 0] = 1; i < 26; i++) bas[i + 1] = bas[i] * mu[i];
  t = bas[26];
  for (j = 0; j < t; j++)
    for (i = 0; i < 26; i++)
      if (pp[i])
        f[j][j + bas[i] -
             (j % bas[i + 1] / bas[i] + 1 != mu[i] ? 0 : bas[i + 1])]++;
  memset((ans), 0, sizeof(ans));
  for (ans[0] = 1; n; n >>= 1) {
    if (n & 1) {
      memset((res), 0, sizeof(res));
      for (i = 0; i < t; i++)
        for (j = 0; j < t; j++) (res[j] += ans[i] * f[i][j]) %= mo;
      memcpy((ans), (res), sizeof(ans));
    }
    memset((g), 0, sizeof(g));
    for (i = 0; i < t; i++)
      for (j = 0; j < t; j++)
        for (k = 0; k < t; k++) (g[i][k] += f[i][j] * f[j][k]) %= mo;
    memcpy((f), (g), sizeof(f));
  }
  for (j = 0; j < t; j++) {
    for (i = 0; i < 26; i++)
      if (pp[i]) {
        bool pd = false;
        for (k = 1; k <= t; k++)
          if (p[i][k] && j % bas[i + 1] / bas[i] % k == 0) pd = true;
        if (!pd) break;
      }
    if (i == 26) (cnt += ans[j]) %= mo;
  }
  printf("%d\n", cnt);
  return 0;
}
