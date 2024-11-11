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
double __pow(long long x, long long y) {
  double res = 1;
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
long long add(vector<long long> a, long long M) {
  long long res = 0;
  for (auto x : a) res = (res + x) % M;
  return res;
}
long long mul(vector<long long> a, long long M) {
  long long res = 1;
  for (auto x : a) res = (res * x) % M;
  return res;
}
long long sub(long long a, long long b, long long M) { return (a - b + M) % M; }
long long div(long long a, long long b, long long M) {
  return (a * mi(b, M)) % M;
}
void umax(long long &a, long long b) { a = max(a, b); }
void umin(long long &a, long long b) { a = min(a, b); }
const long long N = 3e5 + 2, inf = 1e18, M = 1e9 + 7;
long long Test, n, m, k, q;
bool ok = 1;
void test_case() {
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  s = '$' + s;
  t = '$' + t;
  long long i = 1;
  for (; i <= n && s[i] == t[i]; i++)
    ;
  if (i == n + 1) {
    cout << n << '\n';
    return;
  }
  long long cnt = 0, ans = i + 1;
  for (long long j = i + 1; j <= n; j++) {
    cnt = min(k, cnt * 2);
    if (s[j] == 'a') cnt++;
    if (t[j] == 'b') cnt++;
    ans += min(k, cnt + 2);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Test = 1;
  for (long long t = 1; t <= Test; t++) {
    test_case();
  }
  return 0;
}
