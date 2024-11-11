#include <bits/stdc++.h>
using namespace std;
int pw[1000005];
void calc(char *s, int *u, int n) {
  int cur = 1, L = 1, R = n;
  for (int i = 1; i <= n; i++)
    if (i == n) {
      for (int j = n; j >= R + 1; j--) u[j + 1] = u[j];
      while (cur) cur--, u[L++] = i - cur;
      u[L] = n + 1;
    } else if (s[i] == s[i + 1])
      cur++;
    else {
      if (s[i] < s[i + 1]) {
        while (cur) cur--, u[R--] = i - cur;
      } else {
        while (cur) cur--, u[L++] = i - cur;
      }
      cur = 1;
    }
}
void init(char *s, int *u, int n) {
  u[0] = 0;
  for (int i = 1; i <= n; i++) u[i] = (1LL * u[i - 1] * 233 + s[i]) % 777777773;
}
int get(int *u, int x, int ban) {
  if (x < ban) return u[x];
  int res = x - ban + 1;
  return (1LL * u[ban - 1] * pw[res] % 777777773 + u[x + 1] -
          1LL * u[ban] * pw[res] % 777777773 + 777777773) %
         777777773;
}
bool cmp(char *s, char *t, int *u, int *v, int x, int y, int lenu, int lenv) {
  int ed = ~0, l = 1, r = min(lenu - (x <= lenu), lenv - (y <= lenv));
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (get(u, mid, x) == get(v, mid, y))
      l = mid + 1;
    else
      r = mid - 1, ed = mid;
  }
  if (~ed)
    return s[ed + (ed >= x)] < t[ed + (ed >= y)];
  else
    return lenu - (x <= lenu) <= lenv - (y <= lenv);
}
int n, f[1000005], u[1000005], v[1000005], g[1000005], hs1[1000005],
    hs2[1000005];
char s[1000005], t[1000005];
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 1000005 - 5; i++)
    pw[i] = 1LL * pw[i - 1] * 233 % 777777773;
  scanf("%d", &n);
  scanf("%s", s + 1);
  int w = strlen(s + 1);
  calc(s, u, w);
  init(s, hs1, w);
  for (int i = 1; i <= w + 1; i++) f[i] = 1;
  for (int op = 2; op <= n; op++) {
    scanf("%s", t + 1);
    int m = strlen(t + 1), j = 1, sum = 0;
    calc(t, v, m);
    init(t, hs2, m);
    for (int i = 1; i <= m + 1; i++) g[i] = 0;
    for (int i = 1; i <= m + 1; i++) {
      while (j <= w + 1 && cmp(s, t, hs1, hs2, u[j], v[i], w, m))
        sum = (sum + f[j++]) % 1000000007;
      g[i] = sum;
    }
    w = m;
    for (int i = 1; i <= m + 1; i++)
      f[i] = g[i], s[i] = t[i], u[i] = v[i], hs1[i] = hs2[i];
  }
  int ans = 0;
  for (int i = 1; i <= w + 1; i++) ans = (ans + f[i]) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
