#include <bits/stdc++.h>
using namespace std;
template <class T, class first>
inline bool getbit(T a, first i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class first>
inline T setbit(T a, first i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class first>
inline T resetbit(T a, first i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class first>
inline T togglebit(T a, first i) {
  T t = 1;
  return (a ^ (t << i));
}
template <typename T>
T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
T BIGMOD(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
T Bigmod(T base, T power, T mod) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    power >>= 1;
  }
  return ret;
}
template <typename T>
T ModInverse(T number, T mod) {
  return Bigmod(number, mod - 2, mod);
}
template <typename T>
T GCD(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
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
double DEG(double x) { return (180.0 * x) / ((2.0 * acos(0.0))); }
double RAD(double x) { return (x * (double)(2.0 * acos(0.0))) / (180.0); }
template <typename T>
T DIS(T x1, T y1, T x2, T y2) {
  return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
template <typename T>
T ANGLE(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
long long isLeft(T a, T b, T c) {
  return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
void P_ARR(int *ar, int a, int b) {
  if (a > b) swap(a, b);
  if (a <= b) cout << ar[a];
  for (int i = a + 1; i <= b; i++) cout << " " << ar[i];
  cout << endl;
}
const int MX = 1000007;
const int MOD = 1000000007;
const int inf = 1000000000;
int z[MX];
char s[MX];
int z_function() {
  int len = strlen(s);
  memset(z, 0, sizeof z);
  z[0] = 0;
  for (int i = 1, l = 0, r = 0; i < len; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < len && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  int mx = -1;
  int id = -1;
  for (int i = 1; i <= len - 1; i++) {
    if (z[i] == len - i && z[i] <= mx) return i;
    mx = max(mx, z[i]);
  }
  return -1;
}
int main() {
  int tc, cas = 1;
  gets(s);
  int st = z_function();
  if (st == -1)
    return puts("Just a legend");
  else
    puts(s + st);
  return 0;
}
