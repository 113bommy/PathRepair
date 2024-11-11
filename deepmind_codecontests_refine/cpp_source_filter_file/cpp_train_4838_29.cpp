#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m;
long long h1, hl, h2, hs;
long long mod = 1e9 + 9;
char s[MAXN], t[MAXN];
long long f[MAXN];
long long s1[MAXN];
long long s2[MAXN];
long long M(long long a) {
  if (a < 0) return a - a / mod * mod + mod;
  return a - a / mod * mod;
}
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  hl = 1;
  for (int i = 1; i <= m; i++) {
    hs = M(hs * 233 + t[i]);
    hl = M(hl * 233);
  }
  for (int i = 1; i <= n; i++) {
    h1 = M(h1 * 233 + s[i]);
    if (i > m) h2 = M(h2 * 233 + s[i - m] * hl);
    if (M(h1 - h2) == hs)
      f[i] = M(s2[i - m] + i - m + 1);
    else
      f[i] = f[i - 1];
    s1[i] = M(s1[i - 1] + f[i]);
    s2[i] = M(s2[i - 1] + s1[i]);
  }
  printf("%lld\n", s1[n]);
  return 0;
}
