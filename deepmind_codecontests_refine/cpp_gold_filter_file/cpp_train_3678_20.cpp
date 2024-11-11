#include <bits/stdc++.h>
const long long Q = 100005;
inline bool ig(char c) { return c >= 48 && c <= 57; }
inline void read(long long &oi) {
  char c;
  long long f = 1, res = 0;
  while (c = getchar(), (!ig(c)) && c ^ '-')
    ;
  c ^ '-' ? res = (c ^ 48) : f = -1;
  while (c = getchar(), ig(c)) res = res * 10 + (c ^ 48);
  oi = f * res;
}
inline void print(long long oi) {
  if (oi < 0) putchar('-'), oi = ~oi + 1;
  if (oi > 9) print(oi / 10);
  putchar(oi % 10 + 48);
}
inline void write(long long oi, char c) {
  print(oi);
  putchar(c);
}
long long n, m, mod;
long long h[Q], ccf;
struct Edge {
  long long to, nxt;
} e[Q << 1];
inline void edge(long long x, long long y) {
  e[++ccf] = (Edge){y, h[x]};
  h[x] = ccf;
}
long long k, cnt[Q];
bool vst[Q];
inline void dfs(long long x) {
  vst[x] = true;
  ++cnt[k];
  for (register long long i = h[x]; i; i = e[i].nxt)
    if (!vst[e[i].to]) dfs(e[i].to);
}
long long ans = 1;
inline long long pow(long long x, long long y) {
  if (y <= 0) return 1;
  long long res = 1;
  for (; y; y >>= 1, x = (x * x) % mod)
    if (y & 1) res = (res * x) % mod;
  return res;
}
signed main() {
  read(n);
  read(m);
  read(mod);
  if (mod == 1) return write(0, '\n'), 0;
  for (register long long i = 1, x, y; i <= m; ++i)
    read(x), read(y), edge(x, y), edge(y, x);
  for (register long long i = 1; i <= n; ++i)
    if (!vst[i]) ++k, dfs(i);
  if (k == 1) return write(1, '\n'), 0;
  ans = pow(n, k - 2) % mod;
  for (register long long i = 1; i <= k; ++i) ans = (ans * cnt[i]) % mod;
  write(ans, '\n');
  return 0;
}
