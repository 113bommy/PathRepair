#include <bits/stdc++.h>
using namespace std;
char s[200005];
long long n, prex[200005], sufx[200005], prey[200005], sufy[200005];
void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (long long i = 1; i <= n; i++) prex[i] = sufx[i] = prey[i] = sufy[i] = 0;
  long long x = 2e5, y = 2e5, mxx = 2e5, mnx = 2e5, mxy = 2e5, mny = 2e5;
  for (long long i = 1; i <= n; i++) {
    if (s[i] == 'W') x++;
    if (s[i] == 'S') x--;
    if (s[i] == 'A') y++;
    if (s[i] == 'D') y--;
    mxx = max(mxx, x);
    mnx = min(mnx, x);
    mxy = max(mxy, y);
    mny = min(mny, y);
  }
  x = 2e5, y = 2e5;
  for (long long i = 1; i <= n; i++) {
    if (s[i] == 'W') x++;
    if (s[i] == 'S') x--;
    if (s[i] == 'A') y++;
    if (s[i] == 'D') y--;
    if (x == mxx) prex[i] = 1;
    if (x == mnx) sufx[i] = 1;
    if (y == mxy) prey[i] = 1;
    if (y == mny) sufy[i] = 1;
  }
  for (long long i = n; i >= 1; i--)
    prex[i] |= prex[i + 1], sufx[i] |= sufx[i + 1], prey[i] |= prey[i + 1],
        sufy[i] |= sufy[i + 1];
  x = mxx - mnx + 1;
  y = mxy - mny + 1;
  long long ans = x * y;
  if (x > 2) {
    long long u = 2e5;
    bool flag1 = false, flag2 = false;
    if (u == mxx) flag1 = true;
    if (u == mnx) flag2 = true;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == 'W') u++;
      if (s[i] == 'S') u--;
      if (u == mxx && !sufx[i] && !flag1) ans = min(ans, (x - 1) * y);
      if (u == mnx && !prex[i] && !flag2) ans = min(ans, (x - 1) * y);
      if (u == mxx) flag1 = true;
      if (u == mnx) flag2 = true;
    }
  }
  if (y > 2) {
    long long v = 2e5;
    bool flag1 = false, flag2 = false;
    if (v == mxy) flag1 = true;
    if (v == mny) flag2 = true;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == 'A') v++;
      if (s[i] == 'D') v--;
      if (v == mxy && !sufy[i] && !flag1) ans = min(ans, (y - 1) * x);
      if (v == mny && !prey[i] && !flag2) ans = min(ans, (y - 1) * x);
      if (v == mxy) flag1 = true;
      if (v == mny) flag2 = true;
    }
  }
  printf("%lld\n", ans);
}
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) solve();
  return 0;
}
