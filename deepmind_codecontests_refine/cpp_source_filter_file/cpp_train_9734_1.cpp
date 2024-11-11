#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * t;
}
int f[3525][3525][2][2], p, l, n, k, a[3525], tmp[3525];
char ch[3525];
int get() {
  int res = 0;
  for (int i = l - 1; ~i; i--) {
    long long nw = res * 10 + tmp[i];
    tmp[i] = nw / p;
    res = nw % p;
  }
  while (l && !tmp[l - 1]) l--;
  return res;
}
void upd(int &x, int y) { x += x + y >= 1000000007 ? y - 1000000007 : y; }
int dat(int val, int to, int fr) {
  if (to) return (p - dat(val, 0, fr) + 1000000007) % 1000000007;
  return val - fr + 1;
}
int calc(int top, int to, int fr) {
  if (to)
    return (1ll * (top + 1) * p % 1000000007 - calc(top, 0, fr) + 1000000007) %
           1000000007;
  return (1ll * (top + 1) * (top + 2) / 2 % 1000000007 -
          1ll * fr * (top + 1) % 1000000007 + 1000000007) %
         1000000007;
}
int main() {
  p = read(), k = read();
  scanf("%s", ch);
  l = strlen(ch);
  for (int i = 0; i < l; i++) tmp[i] = ch[i] - '0';
  reverse(tmp, tmp + l);
  while (l) a[++n] = get();
  reverse(a + 1, a + n + 1);
  if (k > n) return puts("0"), 0;
  f[0][0][1][0] = 1;
  int val;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      for (int d = 0; d < 2; d++)
        for (int res = 0; res < 2; res++)
          if (val = f[i - 1][j][d][res])
            for (int nr = 0; nr < 2; nr++) {
              int nj = min(nr + j, k);
              if (!d)
                upd(f[i][nj][d][nr],
                    1ll * val * calc(p - 1, res, nr) % 1000000007);
              else {
                upd(f[i][nj][d][nr],
                    1ll * val * dat(a[i], res, nr) % 1000000007);
                if (a[i])
                  upd(f[i][nj][0][nr],
                      1ll * val * calc(a[i] - 1, res, nr) % 1000000007);
              }
            }
  int ans = 0;
  for (int d = 0; d < 2; d++) upd(ans, f[n][k][d][0]);
  printf("%d\n", ans);
  return 0;
}
