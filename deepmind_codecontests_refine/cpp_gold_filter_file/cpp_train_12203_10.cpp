#include <bits/stdc++.h>
using namespace std;
inline int ABS(int x) { return x < 0 ? -x : x; }
inline int calc(int x, int y) {
  int z = 1;
  for (; y; x = (long long)x * x % 998244353, y >>= 1)
    if (y & 1) z = (long long)x * z % 998244353;
  return z;
}
pair<int, pair<int, int>> a[100001 << 1];
inline bool cmp(pair<int, pair<int, int>> u, pair<int, pair<int, int>> v) {
  return (long long)u.second.first * v.second.second <
         (long long)v.second.first * u.second.second;
}
int A[100001], B[100001], C[100001], c[100001], d[100001], e[100001], f[100001],
    g[100001], m, n, x = 1, y, z;
bool b[100001];
int find(int u) { return f[u] ? f[u] = find(f[u]) : u; }
inline void add(int w) { w ? x = (long long)x * w % 998244353 : z++; }
inline void del(int w) {
  w ? x = (long long)x * calc(w, 998244353 - 2) % 998244353 : z--;
}
inline void merge(int u, int v) {
  del(e[u]), del(e[v]), f[v] = u,
                        e[u] = ((long long)(998244353 + e[u] - c[u]) * d[v] +
                                (long long)c[u] * e[v]) %
                               998244353,
                        d[u] = (long long)d[u] * d[v] % 998244353,
                        c[u] = (long long)c[u] * c[v] % 998244353, add(e[u]);
}
inline void left(int u) {
  int v = u;
  while (b[v - 1]) v--;
  int w = find(u);
  del(e[w]);
  for (int i = v; i <= u; g[i++] = -1)
    add(998244353 + 1 - C[i]),
        e[w] = (long long)(e[w] + 998244353 - d[w]) *
               calc(998244353 + 1 - C[i], 998244353 - 2) % 998244353,
        c[w] = (long long)c[w] * calc(998244353 + 1 - C[i], 998244353 - 2) %
               998244353,
        d[w] = (long long)d[w] * calc(C[i], 998244353 - 2) % 998244353;
  for (int i = v; i < u; i++) b[i] = false;
  if (b[u]) b[u] = false, add(e[w]);
}
inline void right(int u) {
  int v = u;
  while (b[v]) v++;
  int w = find(u);
  del(e[w]);
  for (int i = v; i >= u; g[i--] = 1)
    add(C[i]),
        e[w] = (long long)(e[w] + 998244353 - c[w]) *
               calc(C[i], 998244353 - 2) % 998244353,
        c[w] = (long long)c[w] * calc(998244353 + 1 - C[i], 998244353 - 2) %
               998244353,
        d[w] = (long long)d[w] * calc(C[i], 998244353 - 2) % 998244353;
  for (int i = u; i < v; i++) b[i] = false;
  if (b[u - 1]) b[u - 1] = false, add(e[w]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", A + i, B + i, C + i),
        C[i] = C[i] * 828542813ll % 998244353,
        c[i] = (998244353 + 1 - C[i]) % 998244353, d[i] = C[i], e[i] = 1;
  for (int i = 1; i <= n; i++)
    if (C[i] == 0) g[i] = -1;
  for (int i = 1; i <= n; i++)
    if (C[i] == 1) g[i] = 1;
  for (int i = 1; i < n; i++)
    a[++m] = make_pair(i, make_pair(A[i + 1] - A[i], B[i] + B[i + 1])),
    a[++m] = make_pair(-i, make_pair(A[i + 1] - A[i], ABS(B[i] - B[i + 1])));
  std::sort(a + 1, a + m + 1, cmp);
  for (int i = 1, u; i <= m && a[i].second.second; i++)
    if ((u = a[i].first) > 0) {
      if (g[u] == -1 || g[u + 1] == 1) continue;
      int w = (long long)a[i].second.first *
              calc(a[i].second.second, 998244353 - 2) % 998244353;
      if (!z) y = (y + (long long)x * w) % 998244353;
      if (g[u] == 1 && g[u + 1] == -1) return 0 & printf("%d\n", y);
      if (g[u] == 1)
        right(u + 1);
      else if (g[u + 1] == -1)
        left(u);
      else
        b[u] = true, merge(find(u), u + 1);
      if (!z) y = (y + (long long)x * (998244353 - w)) % 998244353;
    } else if (u = -u, B[u] > B[u + 1]) {
      if (g[u] == -1) continue;
      int w = (long long)a[i].second.first *
              calc(a[i].second.second, 998244353 - 2) % 998244353;
      if (!z) y = (y + (long long)x * w) % 998244353;
      if (g[u] == 1) return 0 & printf("%d\n", y);
      left(u);
      if (!z) y = (y + (long long)x * (998244353 - w)) % 998244353;
    } else {
      if (g[++u] == 1) continue;
      int w = (long long)a[i].second.first *
              calc(a[i].second.second, 998244353 - 2) % 998244353;
      if (!z) y = (y + (long long)x * w) % 998244353;
      if (g[u] == -1) return 0 & printf("%d\n", y);
      right(u);
      if (!z) y = (y + (long long)x * (998244353 - w)) % 998244353;
    }
  return 0 & printf("%d\n", y);
}
