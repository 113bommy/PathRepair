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
long long mul(vector<long long> a, long long M) {
  long long res = 1;
  for (auto x : a) res = (res * x) % M;
  return res;
}
long long cl(long long a, long long b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
void umax(long long &a, long long b) { a = max(a, b); }
void umin(long long &a, long long b) { a = min(a, b); }
const long long N = 2e5 + 2, inf = 1e18, M = 998244353, LN = 20;
long long Test, n, m, k, q, a[N];
bool ok = 1;
class BIT {
  long long n, VAL;
  vector<long long> bit;

 public:
  BIT() {}
  BIT(long long _n, long long val) {
    n = _n;
    VAL = val;
    bit.assign(2 * n + 2, VAL);
  }
  long long todo(long long a, long long b) { return a + b; }
  void update(long long i, long long x) {
    i++;
    for (; i <= n; i += (i & -i)) bit[i] = todo(bit[i], x);
  }
  long long get(long long i) {
    i++;
    long long res = VAL;
    for (; i; i -= (i & -i)) res = todo(res, bit[i]);
    return res;
  }
};
void test_case() {
  cin >> n;
  vector<BIT> trees(512);
  for (long long i = 0; i <= 511; i++) trees[i] = BIT(512, 0);
  vector<bool> vis(512);
  vis[0] = 1;
  long long cnt = 1;
  for (long long i = 1, x; i <= n; i++) {
    cin >> x;
    if (!vis[x]) cnt++;
    vis[x] = 1;
    trees[x].update(x, 1);
    for (long long j = 1; j <= 511; j++)
      if (x > 0 && (x ^ j) > 0 && trees[x ^ j].get(x - 1) > 0)
        cnt += !vis[j], vis[j] = 1, trees[j].update(x, 1);
  }
  cout << cnt << '\n';
  for (long long i = 0; i < 511; i++)
    if (vis[i]) cout << i << " ";
  cout << '\n';
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
