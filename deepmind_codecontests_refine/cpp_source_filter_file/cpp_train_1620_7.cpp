#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T mod(T a, T b) {
  while (a < 0) a += b;
  return a % b;
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mod(x * p, m);
    p = mod(p * p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T InverseEuler(T a, T m) {
  return (a == 1 ? 1 : power(a, m - 2, m));
}
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long exEuclid(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long g = exEuclid(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}
long long a[2][2];
long long sol(long long x) {
  long long ret = 0;
  while ((ret * (ret - 1) / 2ll) < x) {
    ret++;
  }
  if ((ret * (ret - 1) / 2ll) == x) {
    return ret;
  }
  return -1;
}
int main(int argc, char *argv[]) {
  io();
  bool f = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
      if (a[i][j]) f = 1;
    }
  }
  if (!f) {
    cout << 0 << '\n';
    return 0;
  }
  long long z = sol(a[0][0]);
  long long o = sol(a[1][1]);
  if (o == -1 || z == -1) {
    cout << "Impossible\n";
    return 0;
  }
  string ans = "";
  f = 0;
  bool flag = (a[0][1] != 0) | (a[1][0] != 0);
  if (flag) {
    o = max(1ll, o);
    z = max(1ll, z);
  }
  for (int i = 0; i < z; i++) ans += "0";
  for (int i = 0; i < o; i++) ans += "1";
  int l = 0, r = z;
  long long cnt01 = z * o;
  long long cnt10 = 0;
  if (a[1][0] > z * o || a[0][1] < o * z) {
    cout << "Impossible\n";
    return 0;
  }
  while (cnt10 < a[1][0]) {
    if (a[1][0] - cnt10 >= z) {
      swap(ans[l], ans[r]);
      l++;
      r++;
      cnt10 += z;
      cnt01 -= z;
    } else {
      long long dif = a[1][0] - cnt10;
      swap(ans[r], ans[r - dif]);
      cnt10 += dif;
      cnt01 -= dif;
    }
  }
  if (cnt01 != a[0][1] || cnt10 != a[1][0]) {
    cout << "Impossible\n";
    return 0;
  }
  cout << ans << '\n';
  return 0;
}
