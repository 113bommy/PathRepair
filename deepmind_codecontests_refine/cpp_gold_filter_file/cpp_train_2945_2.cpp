#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
long long __pow(long long x, long long y, long long M) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long __pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y >>= 1;
    x = (x * x);
  }
  return res;
}
long long mi(long long x, long long M) { return __pow(x, M - 2, M); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long add(long long a, long long b, long long M) { return (a + b) % M; }
long long mul(long long a, long long b, long long M) { return (a * b) % M; }
long long sub(long long a, long long b, long long M) { return (a - b + M) % M; }
long long div(long long a, long long b, long long M) {
  return (a * mi(b, M)) % M;
}
void umax(long long &a, long long b) { a = max(a, b); }
void umin(long long &a, long long b) { a = min(a, b); }
const long long N = 1e5 + 2, inf = 1e18, M = 1e9 + 7;
long long Test, n, m, k, query, prime[10 * N];
bool ok = 1;
void test_case() {
  cin >> n;
  long long x = 1;
  for (; !prime[x] || prime[x + n - 1]; x++)
    ;
  long long y = 1;
  for (; !prime[y] || prime[y + x * (n - 1)]; y++)
    ;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = 0; j < n - 1; j++) cout << 1 << " ";
    cout << x << endl;
  }
  for (long long i = 0; i < n - 1; i++) cout << x << " ";
  cout << y << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Test = 1;
  cin >> Test;
  prime[1] = 1;
  for (long long i = 2; i < 10 * N; i++)
    if (!prime[i])
      for (long long j = 2 * i; j < N; j += i) prime[j] = i;
  while (Test--) test_case();
  return 0;
}
