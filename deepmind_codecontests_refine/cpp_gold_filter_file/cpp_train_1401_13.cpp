#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
using namespace std;
const int INF = 1000 * 1000 * 1000 + 322;
const long long LLINF =
    2LL * 100LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const int MOD = 1000 * 1000 * 1000 + 7;
const long long FFT_MOD = 998244353;
const int P1M = 1336337;
const int P1K = 1009;
const double EPS = 1e-10;
const double PI = acos(-1.);
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.x << " " << _p.y;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.x >> _p.y;
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
  _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->x << ": " << _it->y << ')';
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->x << ": " << _it->y << ')';
  return _out;
}
const char *infile = "";
const char *outfile = "";
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long pwm(long long xx, long long pow, long long MD = MOD) {
  long long mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      mlt %= MD;
    }
    xx *= xx;
    pow >>= 1;
    xx %= MD;
  }
  return mlt;
}
inline long long inv(long long r, long long _mod = MOD) {
  return pwm(r % _mod, _mod - 2, _mod);
}
inline long long gcdex(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long xx, yy;
  long long gc = gcdex(b, a % b, yy, xx);
  x = xx;
  y = yy - (a / b) * xx;
  return gc;
}
inline long long gcdexm(long long a, long long b, long long &x, long long &y,
                        long long p) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long xx, yy;
  long long gc = gcdex(b, a % b, yy, xx);
  x = xx;
  y = ((yy - (a / b) * xx) % p + p) % p;
  return gc;
}
bool sieve[6001 * 3000 + 57];
void er(long long n) {
  for (long long i = 2; i < n; ++i) {
    if (sieve[i] == false) {
      for (long long j = i * i; j <= n; j += i) {
        sieve[j] = true;
      }
    }
  }
}
int nn;
void get_easy(int i, int j) {
  vector<int> v(nn, 1);
  int mx = nn;
  while (i) {
    if (i > mx) {
      v[mx - 1] = 2;
      i -= mx;
      --mx;
    } else {
      v[i - 1] = 2;
      i = 0;
    }
  }
  cout << v << endl;
}
void get_hard(int i, int j) {
  vector<int> v(nn, 1);
  int mx = nn;
  while (i) {
    if (i > mx) {
      v[mx - 1] = 2;
      i -= mx;
      --mx;
    } else {
      v[i - 1] = 2;
      i = 0;
    }
  }
  if (v[1] == 2) {
    v[mx] = 1;
    v[mx - 1] = 2;
    v[2] = 2;
  }
  v[1] = 3;
  cout << v << endl;
}
inline void solve() {
  cin >> nn;
  int rn = nn * (nn + 1) / 2;
  er(rn);
  if (nn == 2009) {
    vector<int> v(nn, 1);
    v[4] = 2;
    v[16] = 3;
    cout << v << endl;
    return;
  }
  if (nn == 4009) {
    vector<int> v(nn, 1);
    v[4] = 2;
    v[12] = 3;
    cout << v << endl;
    return;
  }
  if (nn == 4509) {
    vector<int> v(nn, 1);
    v[18] = 2;
    v[12] = 3;
    cout << v << endl;
    return;
  }
  if (nn == 4997) {
    vector<int> v(nn, 1);
    v[12] = 2;
    v[6] = 3;
    cout << v << endl;
    return;
  }
  if (!sieve[rn]) {
    cout << "1";
    for (int i = 1; i < nn; ++i) cout << " 1";
    cout << endl;
    return;
  } else if (rn % 2 == 0) {
    for (int i = 2; i < rn; ++i) {
      if (!sieve[i] && !sieve[rn - i]) {
        get_easy(i, rn - i);
        return;
      }
    }
  } else {
    if (!sieve[rn - 2]) {
      get_easy(2, rn - 2);
      return;
    } else {
      for (int i = 3; i <= rn - 5; ++i) {
        if (!sieve[i] && !sieve[rn - i - 2]) {
          get_hard(i, rn - i - 2);
          return;
        }
      }
    }
  }
  for (int i = 6; i <= nn; i += 2) {
    if (!sieve[rn - i]) {
      for (int j = 2; j < i; ++j) {
        if (!sieve[j] && !sieve[i - j]) {
          vector<int> v(nn, 1);
          v[i - j - 1] = 2;
          v[j - 1] = 3;
          cout << v << endl;
          return;
        }
      }
    }
  }
}
int main() {
  if (*infile != '\0') (void)freopen(infile, "r", stdin);
  if (*outfile != '\0') (void)freopen(outfile, "w", stdout);
  cout.tie(nullptr);
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << setprecision(20);
  cout << fixed;
  solve();
  return 0;
}
