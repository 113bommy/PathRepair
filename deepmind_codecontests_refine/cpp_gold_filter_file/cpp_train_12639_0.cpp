#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mo = 716203;
int n, m;
char s[N], tp[N];
int inx[N], hs[N], pre[N][27], f[30][N];
long long contr[N][27], influ[N], ans, bst;
int Get(int l, int r) {
  if (l > r) return 0;
  return ((hs[r] - inx[r - l + 1] * 1ll * hs[l - 1] % mo) % mo + mo) % mo;
}
int LCP(int l, int r, int a, int b) {
  int L = 1, R = r - l + 1;
  while (L <= R) {
    int M = L + R >> 1;
    if (Get(l, l + M - 1) == Get(a, a + M - 1))
      L = M + 1;
    else
      R = M - 1;
  }
  return R;
}
int Count(int l, int r, int j) { return pre[r][j] - pre[l - 1][j]; }
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  inx[0] = 1;
  for (int i = 1; i <= n; i++) {
    hs[i] = (hs[i - 1] * 27ll % mo + s[i] - 'a' + 1) % mo;
    s[i] -= 'a';
    for (int j = 0; j < 26; j++) pre[i][j] += pre[i - 1][j] + ((s[i]) == j);
    inx[i] = inx[i - 1] * 27ll % mo;
  }
  for (int i = 1; i <= n; i++) f[0][i] = 1, ans++;
  for (int k = 1; 1; k++) {
    int base = (1 << k) - 1;
    if (base * 2 + 1 > n) break;
    long long delta = (base * 2 + 1) * (base * 2ll + 1);
    for (int i = base + 1; i + base <= n; i++) {
      int L = i - base, R = i + base, ml = i - 1, mr = i + 1;
      int lml = L + ml + 1 >> 1, rmr = R + mr + 1 >> 1;
      if (f[k - 1][lml] && Get(L, ml) == Get(mr, R) && Count(L, R, s[i]) == 1) {
        f[k][i] = 1;
        influ[L] -= delta;
        influ[i] += delta;
        influ[i + 1] -= delta;
        influ[R + 1] += delta;
        ans += delta;
        for (int j = 0; j < 26; j++)
          if (j != s[i]) {
            if (Count(L, R, j) != 0) contr[i][j] -= delta;
          }
      } else {
        if (Get(L, ml) != Get(mr, R)) {
          int cl = LCP(L, ml, mr, R);
          if (Get(L + cl + 1, ml) == Get(mr + cl + 1, R)) {
            if (f[k - 1][rmr] && Count(L, R, s[i]) + (s[mr + cl] == s[i]) -
                                         (s[L + cl] == s[i]) ==
                                     1)
              contr[cl + L][s[mr + cl]] += delta;
            if (f[k - 1][lml] && Count(L, R, s[i]) + (s[L + cl] == s[i]) -
                                         (s[mr + cl] == s[i]) ==
                                     1)
              contr[mr + cl][s[L + cl]] += delta;
          }
        } else {
          if (f[k - 1][lml]) {
            for (int j = 0; j < 26; j++)
              if (Count(L, R, j) == 0) contr[i][j] += delta;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) influ[i] += influ[i - 1];
  long long ori = ans;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 26; j++) ans = max(ans, ori + influ[i] + contr[i][j]);
  printf("%I64d", ans);
}
