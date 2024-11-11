#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int m;
long long n;
long long mod;
pair<long long, long long> getans(long long n, long long lp, long long rp,
                                  long long l, long long r) {
  l = max(l, 0ll);
  r = min(r, n - 1);
  lp = max(lp, 0ll);
  rp = min(rp, n);
  if (l >= n || r < 0 || l > r) return make_pair(0ll, 0ll);
  if (lp >= n || rp <= 0 || lp >= rp) return make_pair(0ll, 0ll);
  if (lp <= 0 && rp >= n) {
    long long a = (r - l + 1);
    long long b = (r + l);
    if (a % 2 == 0)
      a /= 2;
    else
      b /= 2;
    a %= mod;
    b %= mod;
    return make_pair((a * b) % mod, r - l + 1);
  }
  pair<long long, long long> a =
      getans((n + 1) / 2, lp, rp, (l + 1) / 2, r / 2);
  a.first *= 2;
  a.first %= mod;
  pair<long long, long long> b =
      getans(n / 2, lp - (n + 1) / 2, rp - (n + 1) / 2, l / 2, (r + 1) / 2 - 1);
  b.first = ((b.first * 2) + b.second) % mod;
  return make_pair((a.first + b.first) % mod, a.second + b.second);
}
int main() {
  cin >> n >> m >> mod;
  for (int i = 0; i < (m); i++) {
    long long lp, rp, l, r;
    cin >> lp >> rp >> l >> r;
    lp--;
    l--;
    r--;
    pair<long long, long long> res = getans(n, lp, rp, l, r);
    res.first += res.second;
    cout << res.first % mod << endl;
  }
  return 0;
}
