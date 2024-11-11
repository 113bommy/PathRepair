#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int n, m, a, b;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int dx, dy;
inline bool cor(int x, int y) {
  if (x == 1 && y == 1) return 1;
  if (x == 1 && y == m) return 1;
  if (x == n && y == 1) return 1;
  if (x == n && y == m) return 1;
  return 0;
}
long long ans, sum;
map<long long, bool> vis, pd;
int main() {
  n = read(), m = read();
  a = read(), b = read();
  string s;
  cin >> s;
  ans = 1ll * n * m - n - m + 2ll;
  dx = (s[0] == 'D') ? 1 : -1;
  dy = (s[1] == 'R') ? 1 : -1;
  if ((n & 1) && (m & 1)) {
    if (!((a + b) & 1) || ((n == m) && n > 3)) return puts("-1"), 0;
    sum = 1;
    int xx = a, yy = b;
    while (1) {
      int aa, bb;
      if (dx == 1 && dy == 1) {
        aa = n, bb = n + b - a;
        if (bb > m) bb = m, aa = m + a - b;
      } else if (dx == 1 && dy == -1) {
        aa = n, bb = a + b - n;
        if (bb < 1) bb = 1, aa = a + b - 1;
      } else if (dx == -1 && dy == 1) {
        aa = 1, bb = a + b - 1;
        if (bb > m) bb = m, aa = a + b - m;
      } else {
        aa = 1, bb = 1 + b - a;
        if (bb < 1) bb = 1, aa = 1 + a - b;
      }
      if (a ^ aa || b ^ bb) pd[1ll * a * maxn + b] = 1;
      long long val = 1ll * aa * maxn + bb;
      if (pd[val])
        return printf("%lld\n", (2ll * sum >= 1ll * n * m + 1) ? sum : -1), 0;
      pd[val] = 1;
      sum += abs(a - aa);
      a = aa, b = bb;
      if (a == 1 || a == n) dx = -dx;
      if (b == 1 || b == m) dy = -dy;
    }
    return 0;
  }
  while (!cor(a, b)) {
    int aa, bb;
    if (dx == 1 && dy == 1) {
      aa = n, bb = n + b - a;
      if (bb > m) bb = m, aa = m + a - b;
      ans += (aa - a);
    } else if (dx == 1 && dy == -1) {
      aa = n, bb = a + b - n;
      if (bb < 1) bb = 1, aa = a + b - 1;
      ans += (aa - a);
    } else if (dx == -1 && dy == 1) {
      aa = 1, bb = a + b - 1;
      if (bb > m) bb = m, aa = a + b - m;
      ans += (a - aa);
    } else {
      aa = 1, bb = 1 + b - a;
      if (bb < 1) bb = 1, aa = 1 + a - b;
      ans += (a - aa);
    }
    a = aa, b = bb;
    long long val = 1ll * a * maxn + b;
    if (vis[val]) return puts("-1"), 0;
    vis[val] = 1;
    if (a == 1 || a == n) dx = -dx;
    if (b == 1 || b == m) dy = -dy;
  }
  a = b = dx = dy = 1;
  while (1) {
    int aa, bb;
    if (dx == 1 && dy == 1) {
      aa = n, bb = n + b - a;
      if (bb > m) bb = m, aa = m + a - b;
      sum += (aa - a);
    } else if (dx == 1 && dy == -1) {
      aa = n, bb = a + b - n;
      if (bb < 1) bb = 1, aa = a + b - 1;
      sum += (aa - a);
    } else if (dx == -1 && dy == 1) {
      aa = 1, bb = a + b - 1;
      if (bb > m) bb = m, aa = a + b - m;
      sum += (a - aa);
    } else {
      aa = 1, bb = 1 + b - a;
      if (bb < 1) bb = 1, aa = 1 + a - b;
      sum += (a - aa);
    }
    a = aa, b = bb;
    long long val = 1ll * a * maxn + b;
    if (pd[val]) return puts("-1"), 0;
    pd[val] = 1;
    if (a == 1 || a == n) dx = -dx;
    if (b == 1 || b == m) dy = -dy;
    if (sum == 1ll * (n - 1) * (m - 1)) break;
  }
  printf("%lld\n", ans);
  return 0;
}
