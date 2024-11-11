#include <bits/stdc++.h>
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = int(0); i <= int((sz(v)) - 1); ++i) {
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
int read_int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long read_ll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
string read_string() {
  string s;
  cin >> s;
  return s;
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
  const auto level_of = [](long long x) {
    int i = 0;
    while (x >= (1ll << (i + 1))) ++i;
    return i;
  };
  vector<long long> shift(62, 0), c(62);
  for (int i = int(0); i <= int((static_cast<int>((c).size())) - 1); ++i)
    c[i] = (1ll << i);
  for (int q = read_int(); q--;) {
    int type = read_int();
    if (type <= 2) {
      long long x = read_ll(), k = read_ll();
      int i = level_of(x);
      while (i < static_cast<int>((shift).size())) {
        shift[i] = ((shift[i] + k) % c[i] + c[i]) % c[i];
        if (type == 1) break;
        ++i, k *= 2;
      }
    } else {
      long long x = read_ll();
      int i = level_of(x);
      x = (x + shift[i]) % c[i] + c[i];
      while (i >= 0) {
        cout << (x - shift[i] + c[i]) % c[i] + c[i] << " ";
        --i, x /= 2;
      }
      cout << endl;
    }
  }
  return 0;
}
