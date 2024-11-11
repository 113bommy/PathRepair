#include <bits/stdc++.h>
using namespace std;
int n;
char s[30];
long long f[19][4];
long long gao(int x, int tot, bool lim) {
  if (x > n) return 1;
  if (~f[x][tot] && !lim) return f[x][tot];
  long long res = 0;
  int up = lim ? s[x] : 9;
  if (tot == 3) up = 0;
  for (int i = 0; i <= up; ++i)
    res += gao(x + 1, tot + (i != 0), lim && i == s[x]);
  if (!lim) f[x][tot] = res;
  return res;
}
long long calc(long long x) {
  memset(f, -1, sizeof(f));
  if (!x) return 1;
  sprintf(s + 1, "%lld", x);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) s[i] -= '0';
  return gao(1, 0, 1);
}
void solve(void) {
  long long l, r;
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", calc(r) - calc(l - 1));
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
