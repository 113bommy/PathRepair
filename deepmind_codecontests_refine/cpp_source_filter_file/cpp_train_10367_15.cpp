#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e9 + 7;
const long long mod = 1e9 + 7;
long long gt[200005];
void init() {
  gt[0] = 1;
  for (long long i = 1; i <= 200005; i++) {
    gt[i] = (gt[i - 1] * i) % mod;
  }
}
long long pw(long long a, long long p, long long mod) {
  long long res = 1 % mod, x = a % mod;
  while (p) {
    if (p & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    p >>= 1;
  }
  return res;
}
long long C(long long k, long long n) {
  long long a = 1, b = 1, c = 1;
  a = gt[n], b = gt[k], c = gt[n - k];
  b = pw(b, mod - 2, mod);
  c = pw(c, mod - 2, mod);
  a = (a * b) % mod;
  a = (a * c) % mod;
  return a;
}
signed main() {
  init();
  ios_base::sync_with_stdio(0);
  long long f, w, h, okcnt = 0, total = 0;
  cin >> f >> w >> h;
  ++h;
  long long iw = w / h;
  if (h == 1) {
    cout << 1;
    return 0;
  }
  if (w == 0) {
    cout << 0;
    return 0;
  }
  for (long long i = 1; i <= iw; i++) {
    long long n = w - i * h;
    long long add = C(i - 1, n + i - 1);
    long long mul = 0;
    if (f >= i - 1 && i > 1) mul += C(i - 2, f - 1);
    if (f >= i) mul += 2 * C(i - 1, f - 1);
    if (f >= i + 1) mul += C(i, f - 1);
    okcnt = (okcnt + add * mul) % mod;
  }
  for (long long i = 1; i <= w; i++) {
    long long n = w - i;
    long long add = C(i - 1, n + i - 1);
    long long mul = 0;
    if (f >= i - 1 && i > 1) mul += C(i - 2, f - 1);
    if (f >= i) mul += 2 * C(i - 1, f - 1);
    if (f >= i + 1) mul += C(i, f - 1);
    total = (total + (add * mul)) % mod;
  }
  cout << okcnt * pw(total, mod - 2ll, mod) % mod;
  return 0;
}
