#include <bits/stdc++.h>
using namespace std;
const int N = 317, M = 202, p = 10007;
long long hg[N][N];
int n, m, op[N], f[M][M][M], fac[p], ifac[p];
char s[N];
struct matrix {
  int len, ch[N][N];
} g, h;
inline int inc(int a, int b) {
  if (a + b >= p) return a + b - p;
  return a + b;
}
inline int mul(int a, int b) { return 1ll * a * b % p; }
inline int pows(int u, int v) {
  int ans = 1;
  while (v > 0) {
    if (v & 1) ans = mul(ans, u);
    u = mul(u, u), v = v >> 1;
  }
  return ans;
}
inline matrix mul(matrix a, matrix b) {
  matrix x = g;
  x.len = a.len;
  for (int i = 1; i <= x.len; i++)
    for (int j = i; j <= x.len; j++) hg[i][j] = 0;
  for (int i = 1; i <= x.len; i++)
    for (int j = i; j <= x.len; j++)
      for (int k = j; k <= x.len; k++)
        hg[i][k] += 1ll * a.ch[i][j] * b.ch[j][k];
  for (int i = 1; i <= x.len; i++)
    for (int j = i; j <= x.len; j++) x.ch[i][j] = hg[i][j] % p;
  return x;
}
inline matrix powc(matrix u, int v) {
  matrix x = g;
  x.len = u.len;
  for (int i = 1; i <= x.len; i++) x.ch[i][i] = 1;
  while (v > 0) {
    if (v & 1) x = mul(x, u);
    u = mul(u, u), v = v >> 1;
  }
  return x;
}
int main() {
  scanf("%s", s + 1), n = strlen(s + 1), cin >> m, fac[0] = ifac[0] = 1;
  f[0][0][0] = 1;
  for (int i = 1; i < p; i++)
    fac[i] = mul(i, fac[i - 1]), ifac[i] = pows(fac[i], p - 2);
  for (int c = 0; c <= n; c++)
    for (int i = 0; i <= c; i++) {
      int x = c - i;
      for (int t = 0; t <= n; t++) {
        if (!f[i][x][t]) continue;
        if (s[i + 1] != s[n - x]) {
          f[i + 1][x][t + 1] = inc(f[i + 1][x][t + 1], f[i][x][t]);
          f[i][x + 1][t + 1] = inc(f[i][x + 1][t + 1], f[i][x][t]);
        } else if (i + 1 == n - x) {
          f[i + 1][x][t] = inc(f[i + 1][x][t], f[i][x][t]);
        } else if (s[i + 1] == s[n - x])
          f[i + 1][x + 1][t] = inc(f[i + 1][x + 1][t], f[i][x][t]);
      }
    }
  long long cnt = 0;
  int ct = 0;
  if ((n + m) % 2 == 0) {
    op[0] = ++ct;
    for (int i = 1; i <= n; i++)
      op[i] = ++ct, h.ch[ct - 1][ct] += 1, h.ch[op[i]][op[i]] = 24;
    h.ch[ct][ct + 1] -= 1;
    for (int i = 1; i <= (n + 1) / 2; i++)
      op[i + n] = ++ct, h.ch[op[i + n]][op[i + n]] = 25, h.ch[ct - 1][ct] += 1;
    ct++, h.ch[ct][ct] = 26, h.ch[ct - 1][ct] = 1;
    int s = (n + 1) / 2;
    op[n + s + 1] = ct;
    for (int i = 0; i <= n; i++) {
      int j = n - i;
      for (int t = 0; t <= n; t++) {
        int c = (n - t + 1) / 2;
        if (!f[i][j][t]) continue;
        h.ch[op[t]][op[n + s - c + 1]] =
            inc(h.ch[op[t]][op[n + s - c + 1]], f[i][j][t]);
      }
    }
    h.len = ct;
    h = powc(h, (n + m) / 2 + 1);
    cout << h.ch[1][ct] << endl;
  } else {
    op[0] = ++ct;
    for (int i = 1; i <= n; i++)
      op[i] = ++ct, h.ch[ct - 1][ct] += 1, h.ch[op[i]][op[i]] = 24;
    h.ch[ct][ct + 1] -= 1;
    for (int i = 1; i <= (n + 1) / 2; i++)
      op[i + n] = ++ct, h.ch[op[i + n]][op[i + n]] = 25, h.ch[ct - 1][ct] += 1;
    ct++, h.ch[ct][ct] = 26, h.ch[ct - 1][ct] = 1;
    int s = (n + 1) / 2;
    op[n + s + 1] = ct;
    ct++, h.ch[ct - 1][ct] = 26;
    for (int i = 0; i <= n; i++) {
      int j = n - i;
      for (int t = 0; t <= n; t++) {
        int c = (n - t + 1) / 2;
        if (!f[i][j][t]) continue;
        h.ch[op[t]][op[n + s - c + 1]] =
            inc(h.ch[op[t]][op[n + s - c + 1]], f[i][j][t]);
      }
    }
    h.len = ct, h = powc(h, (n + m + 1) / 2 + 1);
    int fh = h.ch[1][ct];
    ct = 0, h = g;
    op[0] = ++ct;
    for (int i = 1; i <= n; i++)
      op[i] = ++ct, h.ch[ct - 1][ct] += 1, h.ch[op[i]][op[i]] = 24;
    h.ch[ct][ct + 1] -= 1;
    for (int i = 1; i <= (n + 1) / 2; i++)
      op[i + n] = ++ct, h.ch[op[i + n]][op[i + n]] = 25, h.ch[ct - 1][ct] += 1;
    ct++, h.ch[ct - 1][ct] = 1, h.ch[ct][ct] = 25;
    op[n + s + 1] = ct;
    for (int i = 0; i <= n; i++) {
      int j = n - i - 1;
      if (j < 0) continue;
      for (int t = 0; t <= n; t++) {
        int c = (n - t + 1) / 2 - 1;
        if (!f[i][j][t]) continue;
        h.ch[op[t]][op[n + s - c + 1]] =
            inc(h.ch[op[t]][op[n + s - c + 1]], f[i][j][t]);
      }
    }
    h.len = ct, h = powc(h, (n + m + 1) / 2), fh += h.ch[1][ct],
    cout << fh << endl;
  }
  return 0;
}
