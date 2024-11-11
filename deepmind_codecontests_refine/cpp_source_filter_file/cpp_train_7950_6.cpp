#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979;
const double PI2 = 6.28318530717958;
const double PId2 = 1.570796326794895;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T a, T b) {
  return (b ? gcd(b, a % b) : a);
}
long long pw(long long a, long long p, int mod) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      --p;
      res = (res * a) % mod;
    } else {
      p >>= 1;
      a = (a * a) % mod;
    }
  }
  return res;
}
inline vector<int> ReadVI(int count) {
  vector<int> arrayname(count);
  for (int i = 0; i < count; i++) cin >> arrayname[i];
  return arrayname;
}
inline vector<long long> ReadVlong(int count) {
  vector<long long> arrayname(count);
  for (int i = 0; i < count; i++) cin >> arrayname[i];
  return arrayname;
}
const int MOD = 1000000007;
const int MAXVALUE = 100001;
pair<long long, long long> frmt(int x, int y) {
  pair<long long, long long> res;
  res.first = x / gcd(x, y);
  res.second = y / gcd(x, y);
  return res;
}
pair<double, long long> f(long long x, long long y, long long b) {
  pair<double, long long> res = make_pair(0, 0);
  long long a1 = abs(x * b - (x * b / y) * y);
  long long a2 = abs(x * b - (x * b / y + 1) * y);
  if (a1 < a2) {
    res.first = a1 / (b + 0.0);
    res.second = x * b / y;
  } else {
    res.first = a2 / (b + 0.0);
    res.second = x * b / y + 1;
  }
  return res;
}
int main() {
  long long x, y, n;
  cin >> x >> y >> n;
  if (n >= y) {
    pair<int, int> ans = frmt(x, y);
    cout << ans.first << "/" << ans.second;
    return 0;
  }
  vector<pair<double, long long> > r(n + 1);
  for (int i = 1; i <= n; i++) {
    pair<double, long long> g = f(x, y, i);
    r[i].first = g.first;
    r[i].second = g.second;
  }
  double m = 9999999999;
  long long a = 0;
  long long b = 0;
  for (long long i = 1; i <= n; i++) {
    if (r[i].first < m) {
      m = r[i].first;
      a = r[i].second;
      b = i;
    }
  }
  pair<long long, long long> ans = frmt(a, b);
  cout << ans.first << "/" << ans.second;
  return 0;
}
