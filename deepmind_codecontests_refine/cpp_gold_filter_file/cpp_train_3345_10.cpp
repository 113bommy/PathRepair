#include <bits/stdc++.h>
using namespace std;
namespace fast_io {
char buf[1 << 12], *p1 = buf, *p2 = buf, sr[1 << 23], z[23], nc;
int C = -1, Z = 0, Bi = 0, ny;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  ny = 1;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != EOF)
    if (nc == 45) ny = -1;
  Bi = 1;
  if (nc < 0) return nc;
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58 && nc != EOF)
    x = (x << 3) + (x << 1) + (nc ^ 48), Bi++;
  return x * ny;
}
inline double find() {
  int a = read(), y = ny, b = (nc != '.') ? 0 : read();
  return (b ? a + (double)b / pow(10, Bi) * y : a);
}
inline int gs(char *s) {
  char c, *t = s;
  while (c = gc(), c <= 32)
    ;
  *s++ = c;
  while (c = gc(), c > 32) *s++ = c;
  return s - t;
}
inline void ot() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
inline void flush() {
  if (C > 1 << 22) ot();
}
template <typename T>
inline void write(T x, char t) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10)
    ;
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = t;
  flush();
}
inline void write(char *s) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) sr[++C] = *s++;
  sr[++C] = '\n';
  flush();
}
}  // namespace fast_io
using namespace fast_io;
const int N = 1e5 + 5, L = 1e6 + 5;
int n, m, d[N], p[N], t[N], x[N];
long long T, ans[N];
vector<int> e[N];
struct bit {
  long long c[N << 4];
  inline void add(int x, long long y) {
    for (; x < L; x += x & -x) c[x] += y;
  }
  inline long long ask(int x) {
    long long y = 0;
    for (; x; x -= x & -x) y += c[x];
    return y;
  }
} t1, t2;
void dfs(int u, long long D) {
  long long cur = T - 2 * D, mx = 0;
  int l = 0, r = L - 1, res = 0, nxt = 0;
  t1.add(t[u], 1ll * x[u] * t[u]), t2.add(t[u], x[u]);
  while (l <= r)
    m = (l + r) >> 1, t1.ask(m) <= cur ? res = m, l = m + 1 : r = m - 1;
  if (res) ans[u] = t2.ask(res), cur -= t1.ask(res);
  r = L - 1;
  res = 0;
  while (l <= r)
    m = (l + r) >> 1, t2.ask(m) ^ ans[u] ? res = m, r = m - 1 : l = m + 1;
  if (res) ans[u] += cur / res;
  for (int v : e[u]) dfs(v, D + d[v]);
  t1.add(t[u], -1ll * x[u] * t[u]);
  t2.add(t[u], -x[u]);
  for (int v : e[u])
    if (ans[v] > mx) mx = ans[v], nxt = v;
  if (u == 1) return ans[u] = max(ans[u], mx), void();
  mx = 0;
  for (int v : e[u])
    if (ans[v] > mx && v ^ nxt) mx = max(mx, ans[v]);
  ans[u] = max(ans[u], mx);
}
int main() {
  n = read(), T = read();
  for (int i = 1; i <= n; i++) x[i] = read();
  for (int i = 1; i <= n; i++) t[i] = read();
  for (int i = 2; i <= n; i++)
    p[i] = read(), d[i] = read(), e[p[i]].push_back(i);
  dfs(1, 0);
  write(ans[1], '\n');
  return ot(), 0;
}
