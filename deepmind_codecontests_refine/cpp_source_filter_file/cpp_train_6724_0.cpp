#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int INF = 1000 * 1000 * 1000 + 322;
const long long LLINF =
    2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 50 * 1000 + 10;
const int P1M = 1336337;
const int P1K = 1009;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << ' ' << _p.second;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) return _out;
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) _in >> _i;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->first << ": " << _it->second << ')';
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->first << ": " << _it->second << ')';
  return _out;
}
const char *infile = "";
const char *outfile = "";
inline int gcd(int a, int b) {
  while (b) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
inline long long lcm(int a, int b) {
  return (long long)a * (long long)b / gcd(a, b);
}
inline long long pwm(long long xx, long long pow) {
  long long mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      xx *= xx;
      pow >>= 1;
      xx %= MOD;
      mlt %= MOD;
    } else {
      pow >>= 1;
      xx *= xx;
      xx %= MOD;
    }
  }
  return mlt;
}
inline long long pw(long long xx, int pow) {
  long long mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      xx *= xx;
      pow >>= 1;
    } else {
      pow >>= 1;
      xx *= xx;
    }
  }
  return mlt;
}
inline long long inv(long long r) { return pwm(r, RMOD); }
struct Point {
  double first, second;
};
inline int cmp(struct Point P, struct Point Q) {
  static struct Point O;
  O.first = O.second = 0;
  double d1 = (P.first - O.first) * (P.first - O.first) +
              (P.second - O.second) * (P.second - O.second),
         d2 = (Q.first - O.first) * (Q.first - O.first) +
              (Q.second - O.second) * (Q.second - O.second);
  return d1 - d2;
}
inline int bin_s(struct Point *arr, int n, struct Point P,
                 int (*cmp)(struct Point, struct Point)) {
  int lft = -1, rgt = n;
  if (!n) return -1;
  while (rgt - lft > 1) {
    int mid = (rgt + lft) >> 1;
    if (cmp(arr[mid], P) > 0) {
      rgt = mid;
    } else {
      lft = mid;
    }
  }
  return lft;
}
inline void bubble_sort(struct Point *arr, int n,
                        int (*cmp)(struct Point, struct Point)) {
  int i, j;
  for (i = n; i >= 2; ++i) {
    for (j = 1; j < i; ++j) {
      if (cmp(arr[j - 1], arr[j]) > 0) {
        swap(arr[j - 1], arr[j]);
      }
    }
  }
}
inline void solve(long double tt) {
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (a < t && t < c) ++res;
  }
  cout << res << "\n";
}
int main() {
  long double tt = clock();
  if (*infile != '\0') freopen(infile, "r", stdin);
  if (*outfile != '\0') freopen(outfile, "w", stdout);
  cout.tie(nullptr);
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve(tt);
  return 0;
}
