#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char c[N];
int pre[N][27], suf[N][27], pf[N][27], sf[N][27], n;
bool jip[N][27], jis[N][27], ji[N][27];
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
inline int solve(int, int, int);
inline int xhz(int l, int r, int i, int dep) {
  if (jis[l][i]) return sf[l][i];
  sf[l][i] = solve(l, r, dep + 1);
  jis[l][i] = 1;
  return sf[l][i];
}
inline int xqz(int l, int r, int i, int dep) {
  if (jip[r][i]) return pf[r][i];
  pf[r][i] = solve(l, r, dep + 1);
  jip[r][i] = 1;
  return pf[r][i];
}
inline int solve(int l, int r, int dep) {
  if (l > r) return 0;
  if (l == r) return 1;
  memset(ji[dep], 0, sizeof(ji[dep]));
  for (int i = 0; i <= 25; i++) {
    int zuo = suf[l][i], you = pre[r][i];
    if (zuo > r || you < l) continue;
    if (you >= zuo) {
      int hu = pf[you][i] ^ pf[zuo][i];
      if (zuo != l) hu ^= xhz(l, zuo - 1, i, dep);
      if (you != r) hu ^= xqz(you + 1, r, i, dep);
      ji[dep][hu] = 1;
    }
  }
  for (int i = 0; i <= 26; i++)
    if (ji[dep][i] == 0) return i;
}
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 25; j++) pre[i][j] = pre[i - 1][j];
    pre[i][c[i] - 'a'] = i;
  }
  for (int i = 0; i <= 25; i++) suf[n + 1][i] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= 25; j++) suf[i][j] = suf[i + 1][j];
    suf[i][c[i] - 'a'] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (pre[i - 1][c[i] - 'a']) {
      int hu = c[i] - 'a';
      if (pre[i - 1][hu] + 1 > i - 1)
        pf[i][hu] = pf[pre[i - 1][hu]][hu];
      else
        pf[i][hu] = pf[i - 1][hu] ^ pf[pre[i - 1][hu]][hu];
      jip[i][hu] = 1;
    }
    for (int j = 0; j <= 25; j++) {
      if (pre[i][j] == 0 || jip[i][j] == 1) continue;
      if (pre[i][j] != i) pf[i][j] = solve(pre[i][j] + 1, i, 0);
      jip[i][j] = 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (suf[i + 1][c[i] - 'a'] != n + 1) {
      int hu = c[i] - 'a';
      if (suf[i + 1][hu] - 1 < i + 1)
        sf[i][hu] = sf[suf[i + 1][hu]][hu];
      else
        sf[i][hu] = sf[i + 1][hu] ^ sf[suf[i + 1][hu]][hu];
      jis[i][hu] = 1;
    }
    for (int j = 0; j <= 25; j++) {
      if (suf[i][j] == n + 1 || jis[i][j] == 1) continue;
      if (suf[i][j] != i) sf[i][j] = solve(i, suf[i][j] - 1, 0);
      jis[i][j] = 1;
    }
  }
  int q = read();
  for (int i = 1, x, y; i <= q; i++) {
    x = read();
    y = read();
    if (solve(x, y, 0))
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}
