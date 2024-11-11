#include <bits/stdc++.h>
template <class c>
int popc(c a) {
  if (sizeof(c) == 8)
    return __builtin_popcountll(a);
  else
    return __builtin_popcount(a);
}
template <class c>
int ctz(c a) {
  if (sizeof(c) == 8)
    return __builtin_ctzll(a);
  else
    return __builtin_ctz(a);
}
template <class c>
int clz(c a) {
  if (sizeof(c) == 8)
    return __builtin_clzll(a);
  else
    return __builtin_clz(a);
}
inline int min(const int &first, const int &second) {
  return (((second - first) >> (32 - 1)) & (first ^ second)) ^ first;
}
inline int max(const int &first, const int &second) {
  return (((second - first) >> (32 - 1)) & (first ^ second)) ^ second;
}
inline long long min(const long long &first, const long long &second) {
  return (((second - first) >> (64 - 1)) & (first ^ second)) ^ first;
}
inline long long max(const long long &first, const long long &second) {
  return (((second - first) >> (64 - 1)) & (first ^ second)) ^ second;
}
using namespace std;
char string_in_buffer[(int)260];
void fast_scan(int &first) { scanf("%d", &first); }
void fast_scan(long long &first) { scanf("%lld", &first); }
void fast_scan(unsigned long long &first) { scanf("%llu", &first); }
void fast_scan(double &first) { scanf("%lf", &first); }
void fast_scan(long double &first) { scanf("%Lf", &first); }
void fast_scan(char &first) {
  scanf("%c", &first);
  if (first == '\n') {
    fast_scan(first);
  }
}
void fast_scan(string &first) {
  scanf("%s", string_in_buffer);
  first = string(string_in_buffer);
}
template <class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
  fast_scan(p.first);
  fast_scan(p.second);
}
template <class T>
void fast_scan(vector<T> &v) {
  for (auto &first : v) fast_scan(first);
}
void fast_print(const int &first) { printf("%d", first); }
void fast_print(const unsigned int &first) { printf("%u", first); }
void fast_print(const long long &first) { printf("%lld", first); }
void fast_print(const unsigned long long &first) { printf("%llu", first); }
void fast_print(const char &first) { printf("%c", first); };
void fast_print(const double &first) { printf("%.15lf", first); }
void fast_print(const long double &first) { printf("%.15Lf", first); }
void fast_print(const string &first) { printf("%s", first.c_str()); }
void fast_print(const char v[]) { fast_print((string)v); }
template <class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
  fast_print(p.first);
  fast_print(' ');
  fast_print(p.second);
}
template <class T>
void fast_print(const vector<T> &v) {
  if (v.empty()) return;
  fast_print(v[0]);
  for (int i = 1; i < v.size(); i++) {
    fast_print(' ');
    fast_print(v[i]);
  }
}
template <class T>
void fast_print(const vector<vector<T>> &v) {
  if (v.empty()) return;
  fast_print(v[0]);
  for (int i = 1; i < v.size(); i++) {
    fast_print('\n');
    fast_print(v[i]);
  }
}
template <class T>
void fast_print(const T &v) {
  for (const auto &first : v) {
    fast_print(first);
    fast_print(' ');
  }
}
using namespace std;
namespace smart_io {
string print_start = "";
string sep = " ";
bool first_print = false;
void precall_print() {
  fast_print(print_start);
  print_start = "\n";
  first_print = true;
}
void _print(deque<string>) {}
template <class T, class... Args>
void _print(deque<string> names, T elem, Args... args) {
  if (!first_print) {
    fast_print("\n");
  } else {
    first_print = false;
  }
  fast_print(names.front());
  fast_print(" = ");
  fast_print(elem);
  names.pop_front();
  _print(names, args...);
}
}  // namespace smart_io
template <class T>
ostream &operator,(ostream &os, const T &object) {
  if (!smart_io::first_print) {
    fast_print(smart_io::sep);
  } else {
    smart_io::first_print = false;
  }
  fast_print(object);
  return os;
}
template <class T>
istream &operator,(istream &is, T &object) {
  fast_scan(object);
  return is;
}
namespace escape__from__random__aetuhoetnuhshe {
using namespace std::chrono;
mt19937 rng(duration_cast<milliseconds>(system_clock::now().time_since_epoch())
                .count());
uniform_real_distribution<> prob_dist(0.0, 1.0);
};  // namespace escape__from__random__aetuhoetnuhshe
namespace typedefs {}
namespace numbers_operation {
template <class T>
inline T floor_mod(T a, const T &b) {
  a %= b;
  if (a < 0) a += b;
  return a;
}
}  // namespace numbers_operation
using namespace numbers_operation;
using namespace typedefs;
using namespace escape__from__random__aetuhoetnuhshe;
int n, m, q;
vector<bool> ok;
bool is_bad(vector<pair<int, int>> Q) {
  sort(Q.begin(), Q.end());
  int _min = 1e9;
  for (pair<int, int> pp : Q) {
    if (pp.first & 1) {
      if (_min <= pp.second) {
        return true;
      }
    } else {
      _min = min(_min, pp.second);
    }
  }
  return false;
}
void solve(vector<pair<int, int>> Q) {
  int l = 0;
  int r = ((int)Q.size()) + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (is_bad(vector<pair<int, int>>(Q.begin(), Q.begin() + m))) {
      r = m;
    } else {
      l = m;
    }
  }
  for (int i = r - 1; i < ((int)ok.size()); i++) {
    ok[i] = false;
  }
}
signed main(signed argc, char *argv[]) {
  cin, n, m, q;
  ok.resize(q, true);
  vector<pair<int, int>> Q;
  Q.resize(q);
  cin, Q;
  for (int i = 0; i < q; i++) {
    Q[i].first--;
    Q[i].second--;
  }
  solve(Q);
  for (int i = 0; i < q; i++) {
    Q[i].first = 2 * n - Q[i].first - 1;
    Q[i].second = 2 * m - Q[i].second - 1;
  }
  solve(Q);
  for (int i = 0; i < q; i++) {
    if (ok[i]) {
      smart_io::precall_print();
      cout, "YES";
    } else {
      smart_io::precall_print();
      cout, "NO";
    }
  }
}
