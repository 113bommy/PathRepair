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
const long long int INF = LLONG_MAX / 10;
const int inf = INT_MAX / 2;
long long int count_bit(long long int _x) {
  long long int _ret = 0;
  while (_x) {
    if (_x % 2 == 1) _ret++;
    _x /= 2;
  }
  return _ret;
}
long long int check_bit(long long int _mask, long long int _i) {
  long long int x = 1;
  return (_mask & (x << _i)) == 0 ? 0 : 1;
}
long long int set_bit(long long int _mask, long long int _i) {
  long long int x = 1;
  _mask = _mask | (x << _i);
  return _mask;
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
vector<string> _split(const string& second, char c) {
  vector<string> v;
  stringstream ss(second);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return v;
}
pair<int, int> operator+(const pair<int, int>& l, const pair<int, int>& r) {
  pair<int, int> ret;
  ret.first = l.first + r.first;
  ret.second = l.second + r.second;
  return ret;
}
struct cmp {
  bool operator()(pair<pair<int, int>, int> const& l,
                  pair<pair<int, int>, int> const& r) {
    return l.first.second < r.first.second;
  }
} myobject;
long long int a[200010], n, k, x;
multimap<long long int, int> m;
int sig = 1;
int main() {
  if (0) {
    freopen("C:\\Users\\Smit Patel\\Desktop\\my.txt", "r", stdin);
    freopen("C:\\Users\\Smit Patel\\Desktop\\out.txt", "w", stdout);
  }
  {
    scanf("%lld", &n);
    ;
    scanf("%lld", &k);
    ;
    scanf("%lld", &x);
    ;
  };
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    ;
    m.insert(make_pair(abs(a[i]), i));
    if (a[i] < 0) sig *= -1;
  }
  while (k--) {
    auto p = *m.begin();
    m.erase(m.begin());
    if (a[p.second] < 0) sig *= -1;
    if (sig == 1)
      a[p.second] -= x;
    else
      a[p.second] += x;
    m.insert(make_pair(abs(a[p.second]), p.second));
    if (a[p.second] < 0) sig *= -1;
  }
  for (int j = 1; j <= n; j++) {
    cout << a[j] << " ";
  }
  cout << endl;
  ;
  return 0;
}
