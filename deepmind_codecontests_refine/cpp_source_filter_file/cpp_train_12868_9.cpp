#include <bits/stdc++.h>
using namespace std;
template <typename T>
T POW(T base, T power) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base);
    base = (base * base);
    power >>= 1;
  }
  return ret;
}
template <typename T>
inline T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (b == 0) ? a : GCD(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / GCD(a, b));
}
template <typename T>
T EUCLIDE(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
long long ar[300007];
long long aa[300007];
long long xx[300007];
long long bb[300007];
long long yy[300007];
int main() {
  int n;
  scanf("%d", &(n));
  ;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &ar[i]);
  }
  aa[1] = ar[1];
  for (int i = 2; i <= n; i++) {
    aa[i] = max(aa[i - 1] + 1, ar[i]);
    xx[i] = aa[i] - ar[i] + xx[i - 1];
  }
  bb[n] = ar[n];
  for (int i = n - 1; i >= 1; i--) {
    bb[i] = max(bb[i + 1] + 1, ar[i]);
    yy[i] = bb[i] - ar[i] + yy[i + 1];
  }
  long long ret = LONG_MAX;
  for (int i = 1; i <= n; i++) {
    long long mx = max(bb[i], aa[i]);
    long long tot = xx[i - 1] + yy[i + 1] + (mx - ar[i]);
    ret = min(ret, tot);
  }
  printf("%lld\n", ret);
  return 0;
}
