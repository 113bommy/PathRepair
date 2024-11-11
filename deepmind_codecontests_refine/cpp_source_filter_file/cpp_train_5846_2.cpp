#include <bits/stdc++.h>
using namespace std;
const long long N = 100010;
const long long P = 998244353;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long x(0), w(1);
  char c = getchar();
  while (c ^ '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * w;
}
long long m, a, ans, b, res, g, vis[N];
queue<long long> q;
inline long long bfs(long long u, long long lim) {
  long long res = 0;
  q.push(u);
  while (!q.empty()) {
    u = q.front();
    ++res;
    q.pop();
    vis[u] = 1;
    if (u + a <= lim && !vis[u + a]) q.push(u + a);
    if (u - b >= 0 && !vis[u - b]) q.push(u - b);
  }
  return res;
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long calc(long long m) {
  long long k = m % g;
  long long n = m - k - 1;
  long long res = 0;
  res = g * (n / g) * (n / g + 1) / 2;
  res += (k + 1) * (m / g);
  return res;
}
signed main() {
  m = read(), a = read(), b = read();
  vis[0] = 1;
  res = 1;
  ans = 1;
  for (long long i = 1; i <= min(2 * max(a, b), m); ++i) {
    if (i - a >= 0 && vis[i - a]) {
      res += bfs(i, i);
    }
    ans += res;
  }
  if (2 * max(a, b) < m) {
    ans += m - 2 * max(a, b);
    g = gcd(a, b);
    ans += calc(m) - calc(2 * max(a, b));
  }
  printf("%lld\n", ans);
  return 0;
}
