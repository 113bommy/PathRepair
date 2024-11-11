#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long mod = 998244353;
const long long g = 3;
template <class T>
void Mul(T &x, T y) {
  x = x * y % mod;
}
template <class T>
void Add(T &x, T y) {
  x = (x + y) % mod;
}
template <class T>
void Sub(T &x, T y) {
  x = (x - y + mod) % mod;
}
template <class T>
void Mn(T &x, T y) {
  x = min(x, y);
}
template <class T>
void Mx(T &x, T y) {
  x = max(x, y);
}
long long qpow(long long x, long long y = mod - 2) {
  long long res = 1;
  while (y) {
    if (y & 1) Mul(res, x);
    Mul(x, x), y >>= 1;
  }
  return res;
}
void Div(long long &x, long long y) { Mul(x, qpow(y)); }
struct Opt {
  long long x, y;
  bool op;
  void ot() {
    cout << x << ' ';
    cout << (op ? '+' : '^') << ' ';
    cout << y << "\n";
  }
} opt[N];
int onum = 0;
int n, m, k;
long long cal_xor(long long x, long long y) {
  opt[++onum].op = 0;
  opt[onum].x = x;
  opt[onum].y = y;
  return (x ^ y);
}
long long cal_add(long long x, long long y) {
  opt[++onum].op = 1;
  opt[onum].x = x;
  opt[onum].y = y;
  return x + y;
}
long long cal_mul(long long x, long long y) {
  long long res = -1;
  while (y) {
    if (y & 1) {
      if (res == -1)
        res = x;
      else
        res = cal_add(res, x);
    }
    y >>= 1, x = cal_add(x, x);
  }
  return res;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return x;
  }
  long long d = exgcd(b, a % b, x, y);
  swap(x, y), y -= x * (a / b);
  return d;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x, tmp, a, b;
  cin >> x;
  tmp = 1;
  while (tmp < x) tmp <<= 1;
  a = cal_mul(x, tmp);
  b = cal_mul(x, tmp - 1);
  a = cal_xor(a, b);
  a = cal_add(a, x);
  long long num1, num2;
  exgcd(a, x, num1, num2);
  if (num1 < 0) swap(num1, num2), swap(a, x);
  num2 = -num2;
  long long r1, r2;
  r1 = cal_mul(a, num1);
  r2 = cal_mul(x, num2);
  if (r1 % 2 == 0) {
    r1 = cal_add(r1, r2);
    r2 = cal_add(r2, r2);
    cal_xor(r1, r2);
  } else
    cal_xor(r1, r2);
  cout << onum << '\n';
  for (int i = 1; i <= onum; i++) opt[i].ot();
}
