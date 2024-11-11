#include <bits/stdc++.h>
using namespace std;
char s[100100];
int n, m, a[100];
bool jud(int len) {
  for (int i = 1; i <= n; i++)
    if (a[i] % len != 0) return 0;
  return 1;
}
void out1(int ans) {
  int i, j, cnt;
  for (i = 1; i <= n; i++) a[i] /= ans;
  cnt = 0;
  for (i = 1; i <= n; i++) cnt += a[i];
  cnt = m / cnt / 2;
  while (cnt--) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= a[i]; j++) printf("%c", 'a' + i - 1);
    for (i = n; i; i--)
      for (j = 1; j <= a[i]; j++) printf("%c", 'a' + i - 1);
  }
  printf("\n");
}
void out2(int ans) {
  int i, j, p, cnt;
  for (i = 1; i <= n; i++) a[i] /= ans;
  cnt = 0;
  for (i = 1; i <= n; i++) cnt += a[i];
  p = 0;
  for (i = 1; i <= n; i++)
    if (!(a[i] & 1))
      for (j = 1; j <= a[i] / 2; j++) s[++p] = s[cnt - p + 1] = 'a' + i - 1;
  for (i = 1; i <= n; i++)
    if (a[i] & 1)
      for (p++; p <= cnt / 2 + 1; p++) s[p] = s[cnt - p + 1] = 'a' + i - 1;
  for (i = 1; i <= m / cnt; i++)
    for (j = 1; j <= cnt; j++) printf("%c", s[j]);
  printf("\n");
}
int main() {
  int i, j, k, ans, res, ti, cnt;
  scanf("%d", &n);
  m = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    m += a[i];
  }
  ans = 0;
  for (i = 2; i <= m; i += 2)
    if (m % i == 0) {
      ti = 2 * m / i;
      if (jud(ti)) {
        ans = ti;
        break;
      }
    }
  res = 0;
  for (i = 3; i <= m; i += 2)
    if (m % i == 0) {
      ti = m / i;
      if (jud(ti)) {
        cnt = 0;
        for (j = 1; j <= n; j++)
          if ((a[j] / ti) & 1) cnt++;
        if (cnt == 1) {
          res = ti;
          break;
        }
      }
    }
  printf("%d\n", max(ans, res));
  if ((!ans) && (!res)) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= a[i]; j++) printf("%c", 'a' + i - 1);
    printf("\n");
  } else if (res <= ans)
    out1(ans);
  else
    out2(res);
  return 0;
}
