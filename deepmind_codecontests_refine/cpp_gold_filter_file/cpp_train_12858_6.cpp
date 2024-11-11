#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);
template <class T>
T& smin(T& x, const T& y) {
  if (x > y) x = y;
  return x;
}
template <class T>
T& smax(T& x, const T& y) {
  if (x < y) x = y;
  return x;
}
template <class T>
T sqr(const T& x) {
  return x * x;
}
template <class T>
T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a)
    ;
  return a + b;
}
template <typename Iterator>
void print(const char* fmt, Iterator first, Iterator last,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; first != last; ++first != last ? printf("%s", delimiter) : 0)
    printf(fmt, *first);
  printf("%s", closing);
}
const int module = static_cast<int>(1e9 + 7);
void inc(int& x, int y, int mod = module) {
  x += y;
  if (x >= mod) x -= mod;
}
int add(int x, int y, int mod = module) {
  inc(x, y, mod);
  return x;
}
int mul(int x, int y, int mod = module) {
  return static_cast<int>(static_cast<long long>(x) * y % mod);
}
void dec(int& x, int y, int mod = module) {
  x -= y;
  if (x < 0) x += mod;
}
int sub(int x, int y, int mod = module) {
  dec(x, y, mod);
  return x;
}
int arithm(long long n) {
  n %= module;
  if (n & 1)
    return mul(n, (n + 1) / 2);
  else
    return mul(n / 2, n + 1);
}
long long n, m;
int main() {
  cin.tie(NULL);
  scanf("%lld%lld", &n, &m);
  int ans = mul(n % module, m % module);
  smin(m, n);
  while (m > n / m) {
    long long q = n / m;
    long long l = n / (q + 1);
    inc(ans, mul(sub(arithm(l), arithm(m)), q % module));
    m = l;
  }
  for (; m > 0; --m) dec(ans, mul(m, n / m % module));
  printf("%d\n", ans);
  return 0;
}
