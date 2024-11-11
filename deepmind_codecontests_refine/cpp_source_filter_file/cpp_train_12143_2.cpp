#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void upmin(T &x, T y) {
  y < x ? x = y : 0;
}
template <typename T>
inline void upmax(T &x, T y) {
  x < y ? x = y : 0;
}
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long OO = 1e18;
const int N = 50;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
char s[N][N];
int fa[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int siz[N];
int id[N];
int f[1 << 23], g[1 << 23];
int main() {
  int n = gi(), m = 0, i, j, c;
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (j = 1; j < i; j++)
      if (s[i][j] == 'A') fa[find(i)] = find(j);
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j < i; j++)
      if (find(i) == find(j) && s[i][j] != 'A') return puts("-1"), 0;
  for (i = 1; i <= n; i++) ++siz[find(i)];
  for (i = 1; i <= n; i++)
    if (fa[i] == i && siz[i] > 1) id[i] = m++;
  if (!m) return cout << n - 1 << endl, 0;
  for (i = 0; i < 1 << m; i++) f[i] = g[i] = 1;
  for (i = 1; i <= n; i++)
    if (siz[find(i)] > 1)
      for (j = i + 1; j <= n; j++)
        if (siz[find(j)] > 1 && s[i][j] == 'X')
          f[1 << id[find(i)] | 1 << id[find(j)]] = 0;
  for (i = 0; i < 1 << m; i++)
    for (j = 0; j < m; j++)
      if (!(i >> j & 1)) f[i | 1 << j] &= f[i];
  for (i = 0; i < m; i++)
    for (j = 0; j < 1 << m; j++)
      if (!(j >> i & 1)) f[j | 1 << i] += f[j];
  for (i = 1; i <= m; i++) {
    c = 0;
    for (j = 0; j < 1 << m; j++) {
      g[j] *= f[j];
      if (__builtin_popcount((((1 << m) - 1) ^ j) & 1))
        c -= g[j];
      else
        c += g[j];
    }
    if (c) return cout << n - 1 + i << endl, 0;
  }
  return 0;
}
