#include <bits/stdc++.h>
using namespace std;
const int modx = 1e9 + 7;
long long f[2000010];
char s[1000010];
int pos[200];
int i, j, k, n, m, len, x, p;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  len = strlen(s + 1);
  f[0] = 1;
  for (i = 1; i <= len; i++) {
    if (pos[s[i]] == 0)
      f[i] = (f[i - 1] * 2) % modx;
    else
      f[i] = (f[i - 1] * 2 - f[pos[s[i]] - 1] + modx) % modx;
    pos[s[i]] = i;
  }
  for (i = len + 1; i <= len + n; i++) {
    f[i] = (f[i - 1] * 2) % modx;
    x = 0;
    p = i;
    for (j = 'a'; j < 'a' + m; j++)
      if (pos[j] < p) {
        p = pos[j];
        x = j;
      }
    if (p > 0) f[i] -= f[p - 1];
    f[i] = (f[i] + modx) % modx;
    pos[x] = i;
  }
  printf("%I64d\n", f[len + n] % modx);
  return 0;
}
