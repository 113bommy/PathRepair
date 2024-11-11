#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 5, Mod = 1e9 + 7;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() { return getchar(); }
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
map<char, int> trans;
char s[MAXN];
int n, ty[10], res, p, tot, ch[2][MAXN], opt[MAXN], S;
inline void Add(int& x, int y) { x += y, x >= Mod ? x -= Mod : 0; }
inline void Sub(int& x, int y) { x -= y, x < 0 ? x += Mod : 0; }
inline void FwtOr(int* F, int len, int opt) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += i << 1)
      for (int k = 0; k < i; k++)
        ~opt ? Add(F[i + j + k], F[j + k]) : Sub(F[i + j + k], F[j + k]);
}
inline void FwtAnd(int* F, int len, int opt) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += i << 1)
      for (int k = 0; k < i; k++)
        ~opt ? Add(F[j + k], F[i + j + k]) : Sub(F[j + k], F[i + j + k]);
}
inline void Build(int x) {
  if (s[p] == '?') return;
  if (isalpha(s[p])) return (void)(opt[x] = trans[s[p]]);
  p++, ch[0][x] = ++tot, Build(tot), p += 2, opt[x] = trans[s[p]], p += 2,
       ch[1][x] = ++tot, Build(tot), ++p;
}
int tmp1[1 << 16], tmp2[1 << 16], F[MAXN][1 << 16];
inline void dfs(int x) {
  if (!opt[x])
    for (int i = 1; i <= 8; i++) F[x][ty[i]]++;
  else if (opt[x] <= 8)
    F[x][ty[opt[x]]]++;
  else if (opt[x] == 9) {
    dfs(ch[0][x]), dfs(ch[1][x]), copy(F[ch[0][x]], F[ch[0][x]] + S + 1, tmp1),
        copy(F[ch[1][x]], F[ch[1][x]] + S + 1, tmp2);
    FwtAnd(tmp1, 1 << n, 1), FwtAnd(tmp2, 1 << n, 1);
    for (int i = 0; i <= S; i++) F[x][i] = 1ll * tmp1[i] * tmp2[i] % Mod;
    FwtAnd(F[x], 1 << n, -1);
  } else if (opt[x] == 10) {
    dfs(ch[0][x]), dfs(ch[1][x]), copy(F[ch[0][x]], F[ch[0][x]] + S + 1, tmp1),
        copy(F[ch[1][x]], F[ch[1][x]] + S + 1, tmp2);
    FwtOr(tmp1, 1 << n, 1), FwtOr(tmp2, 1 << n, 1);
    for (int i = 0; i <= S; i++) F[x][i] = 1ll * tmp1[i] * tmp2[i] % Mod;
    FwtOr(F[x], 1 << n, -1);
  } else {
    dfs(ch[0][x]), dfs(ch[1][x]);
    copy(F[ch[0][x]], F[ch[0][x]] + S + 1, tmp1),
        copy(F[ch[1][x]], F[ch[1][x]] + S + 1, tmp2);
    FwtOr(tmp1, 1 << n, 1), FwtOr(tmp2, 1 << n, 1);
    for (int i = 0; i <= S; i++) F[x][i] = 1ll * tmp1[i] * tmp2[i] % Mod;
    FwtOr(F[x], 1 << n, -1);
    copy(F[ch[0][x]], F[ch[0][x]] + S + 1, tmp1),
        copy(F[ch[1][x]], F[ch[1][x]] + S + 1, tmp2);
    FwtAnd(tmp1, 1 << n, 1), FwtAnd(tmp2, 1 << n, 1);
    for (int i = 0; i <= S; i++) tmp1[i] = 1ll * tmp1[i] * tmp2[i] % Mod;
    FwtAnd(tmp1, 1 << n, -1);
    for (int i = 0; i <= S; i++) Add(F[x][i], tmp1[i]);
  }
}
int main() {
  scanf("%s", s + 1), p = 1, n = read(), S = (1 << n) - 1;
  trans['A'] = 1, trans['B'] = 2, trans['C'] = 3, trans['D'] = 4,
  trans['a'] = 5, trans['b'] = 6, trans['c'] = 7, trans['d'] = 8,
  trans['&'] = 9, trans['|'] = 10, trans['?'] = 11, Build(tot = 1);
  for (int i = 1; i <= n; i++)
    ty[1] |= read() << i - 1, ty[2] |= read() << i - 1,
        ty[3] |= read() << i - 1, ty[4] |= read() << i - 1,
        res |= read() << i - 1;
  for (int i = 5; i <= 8; i++) ty[i] = S ^ ty[i - 4];
  dfs(1), cout << F[1][res];
  return 0;
}
