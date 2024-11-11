#include <bits/stdc++.h>
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = int(0); i <= int((static_cast<int>((v).size())) - 1); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  return os << "]";
}
template <class T>
bool setmax(T& _a, T _b) {
  if (_a < _b) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T& _a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
vector<int> read_vi(int n = -1) {
  if (n < 0) scanf("%d", &n);
  vector<int> a(n);
  for (int i = int(0); i <= int((n)-1); ++i) scanf("%d", &a[i]);
  return a;
}
vector<long long> read_vl(int n = -1) {
  if (n < 0) scanf("%d", &n);
  vector<long long> a(n);
  for (int i = int(0); i <= int((n)-1); ++i) scanf("%lld", &a[i]);
  return a;
}
vector<double> read_vd(int n = -1) {
  if (n < 0) scanf("%d", &n);
  vector<double> a(n);
  for (int i = int(0); i <= int((n)-1); ++i) scanf("%lf", &a[i]);
  return a;
}
vector<pair<int, int> > read_vpi(int n = -1) {
  if (n < 0) scanf("%d", &n);
  vector<pair<int, int> > a(n);
  for (int i = int(0); i <= int((n)-1); ++i)
    scanf("%d%d", &a[i].first, &a[i].second);
  return a;
}
vector<pair<long long, long long> > read_vpl(int n = -1) {
  if (n < 0) scanf("%d", &n);
  vector<pair<long long, long long> > a(n);
  for (int i = int(0); i <= int((n)-1); ++i)
    scanf("%lld%lld", &a[i].first, &a[i].second);
  return a;
}
vector<pair<double, double> > read_vpd(int n = -1) {
  if (n < 0) scanf("%d", &n);
  vector<pair<double, double> > a(n);
  for (int i = int(0); i <= int((n)-1); ++i)
    scanf("%lf%lf", &a[i].first, &a[i].second);
  return a;
}
inline long long powmod(long long a, long long b, long long m) {
  long long r = 1;
  for (; b > 0; b >>= 1, a = a * a % m) {
    if (b & 1) r = r * a % m;
  }
  return r;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n), b(n), c(n);
  for (int i = int(0); i <= int((n)-1); ++i)
    scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
  long long ans = 0;
  int pass = 0;
  for (int i = int(0); i <= int((n)-1); ++i)
    if (c[i] == 0) ++pass;
  assert(pass <= 2);
  if (pass == 2) ans += n - 2;
  for (int i = int(0); i <= int((n)-1); ++i)
    if (c[i]) {
      vector<pair<long long, long long> > ds;
      for (int j = int(i + 1); j <= int((n)-1); ++j)
        if (c[j]) {
          long long d1 = a[i] * a[i] + b[i] * b[i];
          long long d2 = a[j] * a[j] + b[j] * b[j];
          long long x = c[j] * a[j] * d1 - c[i] * a[i] * d2;
          long long y = c[j] * b[j] * d1 - c[i] * b[i] * d2;
          assert(x || y);
          long long g = gcd(x, y);
          x /= g, y /= g;
          if (x < 0 || (x == 0 && y < 0)) x = -x, y = -y;
          ds.push_back({x, y});
        }
      sort((ds).begin(), (ds).end());
      for (int l = 0, r; l < static_cast<int>((ds).size()); ++l) {
        for (r = l; r < static_cast<int>((ds).size()) && ds[l] == ds[r];) ++r;
        ans += (r - l) * (r - l - 1) / 2;
      }
    }
  cout << ans << endl;
  return 0;
}
