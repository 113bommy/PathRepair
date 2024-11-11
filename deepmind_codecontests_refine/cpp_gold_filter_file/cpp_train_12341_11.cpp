#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
inline long long read() {
  register long long x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return f ? -x : x;
}
long long n, X, Y, Z;
long long x[N], y[N], z[N];
inline void max(long long &A, long long B) { A = (A > B ? A : B); }
inline void min(long long &A, long long B) { A = (A < B ? A : B); }
bool check(long long p) {
  long long l[5], r[5], L[5], R[5];
  for (long long i = 0; i <= 3; ++i) r[i] = R[i] = 6e18, l[i] = L[i] = -6e18;
  for (long long i = 1; i <= n; ++i) {
    min(r[0], x[i] + y[i] + z[i] + p);
    max(l[0], x[i] + y[i] + z[i] - p);
    min(r[1], -x[i] + y[i] + z[i] + p);
    max(l[1], -x[i] + y[i] + z[i] - p);
    min(r[2], x[i] - y[i] + z[i] + p);
    max(l[2], x[i] - y[i] + z[i] - p);
    min(r[3], x[i] + y[i] - z[i] + p);
    max(l[3], x[i] + y[i] - z[i] - p);
  }
  for (long long A = 0; A < 2; ++A) {
    L[0] = l[0] - A * 3;
    R[0] = r[0] - A * 3;
    for (long long i = 1; i <= 3; ++i) L[i] = l[i] - A, R[i] = r[i] - A;
    for (long long i = 0; i <= 3; ++i) L[i] = (L[i] + 1) >> 1, R[i] >>= 1;
    for (long long i = 0; i <= 3; ++i)
      if (L[i] > R[i]) goto bk;
    if (L[1] + L[2] + L[3] <= R[0] && R[1] + R[2] + R[3] >= L[0]) {
      long long a = L[1], b = L[2], c = L[3];
      if (a + b + c < L[0]) a += min(R[1] - L[1], L[0] - a - b - c);
      if (a + b + c < L[0]) b += min(R[2] - L[2], L[0] - a - b - c);
      if (a + b + c < L[0]) c += min(R[3] - L[3], L[0] - a - b - c);
      X = b + c + A;
      Y = a + c + A;
      Z = a + b + A;
      return true;
    }
  bk:;
  }
  return false;
}
void solve() {
  n = read();
  for (long long i = 1; i <= n; ++i)
    x[i] = read(), y[i] = read(), z[i] = read();
  long long l = 0, r = 6e18, mid, ans;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  check(ans);
  cout << X << ' ' << Y << ' ' << Z << '\n';
}
signed main() {
  long long T = read();
  while (T--) solve();
  return 0;
}
