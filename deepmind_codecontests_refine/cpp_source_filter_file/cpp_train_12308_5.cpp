#include <bits/stdc++.h>
using namespace std;
long long powerm(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long power(long long x, unsigned long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    long long res = (x % m + m) % m;
    return res;
  }
}
long long d[200001];
long long par[200001];
long long tin[200001];
long long tout[200001];
long long t = 0;
long long dp[200001];
long long ans[200001];
struct cmp {
  bool operator()(pair<long long, long long> x, pair<long long, long long> y) {
    return (x.first < y.first || (x.first == y.first && x.second < y.second));
  }
};
int32_t main() {
  long long q = 1;
  long long Q = 1;
  while (q--) {
    long long n;
    cin >> n;
    pair<long long, long long> a[n + 2];
    a[0] = {0, 0};
    for (long long i = 1; i <= n; i++) cin >> a[i].first;
    for (long long i = 1; i <= n; i++) cin >> a[i].second;
    a[n + 1] = {1e9, 0};
    sort(a + 1, a + n + 1);
    priority_queue<long long> q;
    long long s = 0, ans = 0;
    for (long long i = 1; i <= n + 1; i++) {
      long long c = a[i].first - a[i - 1].first;
      while (c && !q.empty()) {
        s -= q.top();
        ans += s;
        q.pop();
        c--;
      }
      q.push(a[i].second);
      s += a[i].second;
    }
    cout << ans;
  }
}
