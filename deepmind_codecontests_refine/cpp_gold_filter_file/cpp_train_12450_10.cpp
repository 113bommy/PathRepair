#include <bits/stdc++.h>
using namespace std;
template <class T>
T max3(T a, T b, T c) {
  return max2(max2(a, b), c);
}
template <class T>
T min3(T a, T b, T c) {
  return min2(min2(a, b), c);
}
template <class T>
T max4(T a, T b, T c, T d) {
  return max2(max2(a, b), max2(c, d));
}
template <class T>
T min4(T a, T b, T c, T d) {
  return min2(min2(a, b), max2(c, d));
}
const long long int mod = 1000000007ll;
const long long int MOD = 1000000009ll;
long long int bit_count(long long int _x) {
  long long int _ret = 0;
  while (_x) {
    if (_x % 2 == 1) _ret++;
    _x /= 2;
  }
  return _ret;
}
long long int bit(long long int _mask, long long int _i) {
  long long int x = 1;
  return (_mask & (x << _i)) == 0 ? 0 : 1;
}
long long int powermod(long long int _a, long long int _b,
                       long long int _m = mod) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
long long int power(long long int _a, long long int _b) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long int add(long long int a, long long int b, long long int m = mod) {
  long long int x = a + b;
  while (x >= m) x -= m;
  return x;
}
long long int sub(long long int a, long long int b, long long int m = mod) {
  long long int x = a - b;
  while (x < 0) x += m;
  return x;
}
long long int mul(long long int a, long long int b, long long int m = mod) {
  long long int x = a * b;
  x %= m;
  return x;
}
long long int gcd(long long int a, long long int b) {
  if (a < b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  }
  if (b == 0) return a;
  long long int t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
pair<int, int> operator+(const pair<int, int>& l, const pair<int, int>& r) {
  pair<int, int> ret;
  ret.first = l.first + r.first;
  ret.second = l.second + r.second;
  return ret;
}
struct cmp {
  bool operator()(int const& l, int const& r) { return l > r; }
} myobject;
long long int n, a[100010], b[100010], c, first, p;
double po, con, t, l, r, fix;
int main() {
  {
    scanf("%lld", &n);
    ;
    scanf("%lld", &p);
    ;
  };
  po = p;
  c = 0;
  con = 0;
  for (int i = 0; i < n; i++) {
    {
      scanf("%lld", &a[i + 1]);
      ;
      scanf("%lld", &b[i + 1]);
      ;
    };
    c += a[i + 1];
    con += a[i + 1];
    first += b[i + 1];
    fix += b[i + 1];
  }
  if (p >= con)
    cout << "-1";
  else {
    l = 0.0;
    r = 1e17;
    while (r - l > 0.00001) {
      double mid = (l + r) / 2;
      double tot = 0;
      for (int i = 1; i <= n; i++) tot += max((double)0, mid * a[i] - b[i]);
      if (tot <= mid * po)
        l = mid;
      else
        r = mid;
    }
    printf("%.10f", r);
  }
  return 0;
}
