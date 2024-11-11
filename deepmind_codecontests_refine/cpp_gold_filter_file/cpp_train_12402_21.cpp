#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
int ctz(unsigned x) { return __builtin_ctz(x); }
int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
int clz(unsigned x) { return __builtin_clz(x); }
int clzll(unsigned long long x) { return __builtin_clzll(x); }
int popcnt(unsigned x) { return __builtin_popcount(x); }
int popcntll(unsigned long long x) { return __builtin_popcountll(x); }
int bsr(unsigned x) { return 31 ^ clz(x); }
int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
const int k = 30;
int base[32];
int a[200016], p[200016];
void add(int x) {
  for (int i = k - 1; i >= 0; --i) {
    if (x & (1 << i)) x ^= base[i];
  }
  if (!x) return;
  for (int i = k - 1; i >= 0; --i) {
    if (x & (1 << i)) return void(base[i] = x);
  }
}
int main() {
  canhazfast();
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    p[i + 1] = p[i] ^ a[i];
  }
  if (!p[n]) return cout << "-1", 0;
  for (int i = 1; i <= n; ++i)
    if (p[i]) add(p[i]);
  for (int i = 0; i < k; ++i)
    if (base[i]) ++ans;
  cout << ans;
  return 0;
}
