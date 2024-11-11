#include <bits/stdc++.h>
using namespace std;
const int m = (1 << 16), Mod = 1e9 + 7, N = m + 5, M = 505;
char s[M];
vector<int> vt;
int len, f[M][N], tA[4], ta[4], t[N], ch[N][2], tl[N], tr[N], tt[N], rt, cnt, n,
    q[2], ans;
inline void add(int& x, int y) { x = (x + y >= Mod ? x + y - Mod : x + y); }
inline void sub(int& x, int y) { x = (x - y < 0 ? x - y + Mod : x - y); }
void fwt_or(int* a, int o) {
  for (int i = 1; i < m; i <<= 1)
    for (int j = 0; j < m; j += (i << 1))
      for (int k = 0; k < i; ++k)
        o == 1 ? add(a[i + j + k], a[j + k]) : sub(a[i + j + k], a[j + k]);
}
void fwt_and(int* a, int o) {
  for (int i = 1; i < m; i <<= 1)
    for (int j = 0; j < m; j += (i << 1))
      for (int k = 0; k < i; ++k)
        o == 1 ? add(a[j + k], a[i + j + k]) : sub(a[j + k], a[i + j + k]);
}
int solve(int l, int r) {
  if (l == r) {
    int ns = 0;
    if ('A' <= s[l] && s[l] <= 'D') f[l][tA[s[l] - 'A']] = 1;
    if ('a' <= s[l] && s[l] <= 'd') f[l][ta[s[l] - 'a']] = 1;
    if (s[l] == '?')
      for (auto s : vt) ++f[l][s];
    return l;
  }
  int t = 1, x;
  for (x = l + 1; t; ++x) t += (s[x] == '(' ? 1 : (s[x] == ')' ? -1 : 0));
  ch[x][0] = solve(l + 1, x - 2), ch[x][1] = solve(x + 2, r - 1);
  if (s[x] != '|') {
    memcpy(tl, f[ch[x][0]], sizeof(tl));
    memcpy(tr, f[ch[x][1]], sizeof(tr));
    fwt_and(tl, 1), fwt_and(tr, 1);
    for (int i = 0; i < m; ++i) tt[i] = (1ll * (tl[i]) * (tr[i]) % Mod);
    fwt_and(tt, -1);
    for (int i = 0; i < m; ++i) add(f[x][i], tt[i]);
  }
  if (s[x] != '&') {
    memcpy(tl, f[ch[x][0]], sizeof(tl));
    memcpy(tr, f[ch[x][1]], sizeof(tr));
    fwt_or(tl, 1), fwt_or(tr, 1);
    for (int i = 0; i < m; ++i) tt[i] = (1ll * (tl[i]) * (tr[i]) % Mod);
    fwt_or(tt, -1);
    for (int i = 0; i < m; ++i) add(f[x][i], tt[i]);
  }
  return x;
}
int main() {
  scanf("%s", s + 1), len = strlen(s + 1);
  for (int i = 0; i < 4; ++i) {
    int ns = 0;
    for (int s = 0; s < (1 << 4); ++s)
      if (s & (1 << i)) ns |= (1 << s);
    tA[i] = ns, ta[i] = ns ^ (m - 1), vt.push_back(ns),
    vt.push_back(ns ^ (m - 1));
  }
  rt = solve(1, len);
  scanf("%d", &n);
  while (n--) {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    q[e] |= 1 << (a | (b << 1) | (c << 2) | (d << 3));
  }
  for (int s = 0; s < m; ++s)
    if (!(s & q[0]) && (s & q[1]) == q[1]) add(ans, f[rt][s]);
  printf("%d\n", ans);
}
