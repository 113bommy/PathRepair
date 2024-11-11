#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long nm = 0;
  bool fh = 1;
  char cw = getchar();
  for (; !isdigit(cw); cw = getchar()) fh ^= (cw == '-');
  for (; isdigit(cw); cw = getchar()) nm = nm * 10 + (cw - '0');
  return fh ? nm : -nm;
}
int n, m, fs[1100010], nt[1100010 << 1], to[1100010 << 1], tmp;
int h[1100010], d[1100010];
long long Fu[1100010], Fd[1100010], v[1100010], ans, t[1100010];
inline void link(int x, int y) { nt[tmp] = fs[x], fs[x] = tmp, to[tmp++] = y; }
inline void DP(int x, int last) {
  for (int i = fs[x]; i != -1; i = nt[i])
    if (to[i] ^ last) DP(to[i], x);
  long long now = 0;
  m = 0;
  for (int i = fs[x]; i != -1; i = nt[i])
    if (to[i] ^ last) now += Fd[to[i]], t[++m] = Fu[to[i]] - Fd[to[i]];
  sort(t + 1, t + m + 1);
  for (int out = m, in = 0, i = 0; i <= m; i++, out--, in++) {
    if (!last)
      ans = min(ans, now + (long long)max(out, in) * v[x]);
    else {
      if (h[x] <= h[last])
        Fu[x] = min(Fu[x], now + (long long)max(out + 1, in) * v[x]);
      if (h[x] >= h[last])
        Fd[x] = min(Fd[x], now + (long long)max(out, in + 1) * v[x]);
    }
    now += t[i + 1];
  }
}
int main() {
  n = read(), memset(fs, -1, sizeof(fs));
  for (int x = 1; x <= n; x++) Fd[x] = Fu[x] = 40000000000000000ll;
  for (int x = 1; x <= n; x++) v[x] = read();
  for (int x = 1; x <= n; x++) h[x] = read();
  for (int i = 1, x, y; i < n; i++)
    x = read(), y = read(), link(x, y), link(y, x);
  ans = 40000000000000000ll, DP(1, 0), printf("%lld\n", ans);
  return 0;
}
