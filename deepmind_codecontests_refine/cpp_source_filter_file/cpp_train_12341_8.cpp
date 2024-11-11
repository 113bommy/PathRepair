#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long x[100010], y[100010], z[100010], l[4], r[4], X, Y, Z;
int T, n;
bool check(long long mid) {
  for (int i = 0; i < 4; i++) l[i] = -6e18, r[i] = 6e18;
  for (int i = 1; i <= n; i++) {
    l[0] = max(l[0], x[i] + y[i] + z[i] - mid);
    r[0] = min(r[0], x[i] + y[i] + z[i] + mid);
    l[1] = max(l[1], x[i] - y[i] - z[i] - mid);
    r[1] = min(r[1], x[i] - y[i] - z[i] + mid);
    l[2] = max(l[2], -x[i] + y[i] - z[i] - mid);
    r[2] = min(r[2], -x[i] + y[i] - z[i] + mid);
    l[3] = max(l[3], x[i] + y[i] - z[i] - mid);
    r[3] = min(r[3], x[i] + y[i] - z[i] + mid);
  }
  for (int i = 0; i < 3; i++)
    if (l[i] > r[i]) return false;
  l[3] = max(l[3], l[0] + l[1] + l[2]);
  r[3] = min(r[3], r[0] + r[1] + r[2]);
  if (l[3] > r[3]) return false;
  for (int i = 0; i < 2; i++) {
    long long a = l[0] + ((l[0] ^ i) & 1), b = l[1] + ((l[1] ^ i) & 1),
              c = l[2] + ((l[2] ^ i) & 1), tar = l[3] + ((l[3] ^ i) & 1);
    if (a > r[0] || b > r[1] || c > r[2] || tar > r[3]) continue;
    if (a + b + c < tar) a += min((r[0] - a) / 2, (tar - a - b - c) / 2) * 2;
    if (a + b + c < tar) b += min((r[1] - b) / 2, (tar - a - b - c) / 2) * 2;
    if (a + b + c < tar) c += min((r[2] - c) / 2, (tar - a - b - c) / 2) * 2;
    if (a + b + c >= l[3] && a + b + c <= r[3]) {
      X = (a + b) / 2;
      Y = (a + c) / 2;
      Z = -(b + c) / 2;
      return true;
    }
  }
  return false;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read(), z[i] = read();
    long long l = 0, r = 2e18;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    printf("%lld %lld %lld\n", X, Y, Z);
  }
  return 0;
}
