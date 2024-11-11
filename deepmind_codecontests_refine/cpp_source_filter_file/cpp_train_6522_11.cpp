#include <bits/stdc++.h>
template <typename T1, typename T2>
inline bool chkmin(T1& x, const T2& y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool chkmax(T1& x, const T2& y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
using namespace std;
const long long maxn = 2e5 + 20;
ostream& operator<<(ostream& out, vector<long long>& v) {
  for (auto& x : v) out << x << ' ';
  return out;
}
ostream& operator<<(ostream& out, pair<long long, long long>& v) {
  out << v.first << ", " << v.second;
  return out;
}
istream& operator>>(istream& in, pair<long long, long long>& a) {
  in >> a.first >> a.second;
  return in;
}
const long long inf = (long long)2e9;
const long double pi = asin(1) * 2;
const long double eps = 1e-8;
const long long mod = (long long)1e9 + 7;
const long long ns = 97;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long kek(vector<long long> goo, long long d, long long p, long long b,
              long long k) {
  long long s = 0;
  long long j = 0;
  for (long long i = 0; i < (long long)goo.size(); ++i) {
    if (i < k || i >= (long long)goo.size() - k && p == 2) {
      s += goo[i];
      continue;
    }
    long long need = goo[i] - b;
    if (need >= 0)
      s += need;
    else {
      need *= -1;
      long long delta = min(need, s);
      need -= delta;
      s -= delta;
      long long days = 0;
      while (need > 0) {
        while (j < (long long)goo.size() && goo[j] == 0 || j <= i) ++j;
        if (j >= (long long)goo.size()) return 0;
        delta = min(need, goo[j]);
        need -= delta;
        goo[j] -= delta;
        chkmax(days, (j - i + d - 1) / d);
      }
      if (days > i + 1) return 0;
    }
  }
  return 1;
}
long long bs(vector<long long>& goo, long long d, long long p, long long b) {
  long long l = -1, r = (long long)goo.size() + 1;
  auto moo = goo;
  reverse(moo.begin(), moo.end());
  while (r - l > 1) {
    long long m = (r + l) / 2;
    if (p == 1) {
      if (kek(goo, d, p, b, m))
        r = m;
      else
        l = m;
    } else {
      if (kek(goo, d, p, b, m) && kek(moo, d, p, b, m))
        r = m;
      else
        l = m;
    }
  }
  return r;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long p, n, d, b;
  cin >> p >> n >> d >> b;
  vector<long long> goo(n);
  for (auto& x : goo) cin >> x;
  long long ans = bs(goo, d, p, b);
  cout << ans << '\n';
}
