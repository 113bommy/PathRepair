#include <bits/stdc++.h>
const long long Inf = 2e14;
using namespace std;
long long c[100010];
int n;
char s[2][100010], t[2][101000];
long long ans[2];
int main() {
  long long ansp;
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%I64d", &c[i]);
  int now = 0, last = 1;
  for (i = 1; i <= n; ++i) {
    scanf("%s", s[now]);
    int lenp = strlen(s[now]);
    for (j = 1; j <= lenp; ++j) t[now][lenp - j] = s[now][j - 1];
    t[now][lenp] = '\0';
    long long x = Inf, y = Inf;
    if (i == 1 || strcmp(s[now], s[last]) >= 0) {
      x = min(x, ans[0]);
    }
    if (i == 1 || strcmp(s[now], t[last]) >= 0) {
      x = min(x, ans[1]);
    }
    if (i == 1 || strcmp(t[now], s[last]) >= 0) {
      y = min(y, ans[0] + c[i]);
    }
    if (i == 1 || strcmp(t[now], t[last]) >= 0) {
      y = min(y, ans[1] + c[i]);
    }
    ans[0] = x, ans[1] = y;
    now ^= 1;
    last ^= 1;
  }
  ansp = min(ans[0], ans[1]);
  if (ansp >= Inf - 10LL)
    puts("-1");
  else
    printf("%I64d\n", ansp);
  return 0;
}
