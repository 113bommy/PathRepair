#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
long long mod = 1000000007;
double eps = 1e-12;
double pi = acos(-1);
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
int add(int a, int b, int c = MOD) {
  int res = a + b;
  return (res >= c ? res - c : res);
}
int mod_neg(int a, int b, int c = MOD) {
  int res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}
int mul(int a, int b, int c = MOD) {
  long long res = (long long)a * b;
  return (res >= c ? res % c : res);
}
int muln(int a, int b, int c = MOD) {
  long long res = (long long)a * b;
  return ((res % c) + c) % c;
}
long long mulmod(long long a, long long b, long long m = MOD) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, z, n));
}
const int FACSZ = 1;
int fact[FACSZ], ifact[FACSZ];
void precom(int c = MOD) {
  fact[0] = 1;
  for (long long i = 1; i < FACSZ; i++) fact[i] = mul(fact[i - 1], i, c);
  ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
  for (long long i = 0; i < FACSZ - 1; i++) {
    ifact[i] = mul(i + 1, ifact[i + 1], c);
  }
}
int ncr(int n, int r, int c = MOD) {
  return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
void solve() {
  int n;
  cin >> n;
  string s, k;
  cin >> s;
  k = s;
  long long count = 0;
  sort(s.begin(), s.end());
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == k[i]) {
      count++;
    }
  }
  cout << n - count;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
