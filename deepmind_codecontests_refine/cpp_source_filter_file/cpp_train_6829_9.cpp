#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
inline long long MAX2(long long a, long long b) {
  return (a) > (b) ? (a) : (b);
}
inline long long MAX3(long long a, long long b, long long c) {
  return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));
}
inline long long MIN2(long long a, long long b) {
  return (a) < (b) ? (a) : (b);
}
inline long long MIN3(long long a, long long b, long long c) {
  return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));
}
int mod = 998244353;
int64_t extGcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1;
  int64_t d = extGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline long long addmod(long long a, long long b) {
  a = a % mod + b % mod;
  if (a > mod) a %= mod;
  return a;
}
inline long long submod(long long a, long long b) {
  a = a % mod - b % mod;
  if (a < 0) a += mod;
  return a;
}
inline long long mulmod(long long a, long long b) {
  return (a % mod * b % mod) % mod;
}
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int DX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int DY[] = {1, 2, 2, 1, -1, -2, -2, -1};
inline long long exp(long long a, long long b) {
  if (a == 0) return 0ll;
  long long r = 1LL;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % mod);
      r = (r + mod) % mod;
    }
    b /= 2;
    a = (a % mod) * (a % mod);
    a = (a + mod) % mod;
  }
  return (r + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}
unsigned long int setbits(long long n) {
  unsigned long int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
int main() {
  if (fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  long long z = n - (n - n / 2);
  long long y = (n - z) / (k + 1);
  long long x = k * y;
  z = (n - (x + y));
  cout << y << " " << x << " " << z << '\n';
}
