#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const long long N = 45;
long long n, m, ans, v[N], f[1 << 21];
vector<long long> g[N];
long long fpow(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) res = res * x;
  return res;
}
bool dfs(long long x, long long c) {
  v[x] = c;
  bool fl = 1;
  for (long long y : g[x]) {
    if (v[y] == -1)
      fl &= dfs(y, !c);
    else if (v[y] == c)
      fl = 0;
  }
  return fl;
}
signed main() {
  read(n);
  read(m);
  for (long long i = 1; i <= n; i++) v[i] = -1;
  for (long long i = 1, x, y; i <= m; i++) {
    read(x);
    read(y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long mid = n >> 1;
  for (long long S = 0; S < 1 << mid; S++) {
    long long s = S << 1;
    bool fl = 1;
    for (long long x = 1; x <= mid && fl; x++)
      if (s >> x & 1)
        for (long long y : g[x])
          if (y <= mid && s >> y & 1) fl = 0;
    f[S] = fl;
  }
  for (long long i = 0; i < mid; i++)
    for (long long s = 0; s < 1 << mid; s++)
      if (s >> i & 1) f[s] += f[s ^ 1 << i];
  for (long long S = 0; S < 1 << n - mid; S++) {
    long long s = S << mid + 1;
    bool fl = 1;
    for (long long x = mid + 1; x <= n && fl; x++)
      if (s >> x & 1)
        for (long long y : g[x])
          if (y > mid && s >> y & 1) fl = 0;
    if (!fl) continue;
    long long aim = (1 << mid) - 1 << 1;
    for (long long x = mid + 1; x <= n; x++)
      if (s >> x & 1)
        for (long long y : g[x])
          if (y <= mid) aim = (aim | 1 << y) ^ 1 << y;
    ans -= 2 * f[aim >> 1];
  }
  if (m) ans += fpow(2, n);
  long long cnt = 0, single = 0;
  bool fl = 1;
  for (long long i = 1; i <= n; i++)
    if (v[i] == -1) {
      if (g[i].empty()) single++;
      cnt++;
      fl &= dfs(i, 0);
    }
  if (!fl) ans -= fpow(2, cnt);
  ans += fpow(2, single + 1);
  write(ans);
}
