#include <bits/stdc++.h>
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
signed main(signed argc, char *argv[]) {
  int tests;
  cin, tests;
  for (int test = 0; test < (tests); test++) {
    int n, m;
    cin, n, m;
    vector<string> v(n);
    cin, v;
    vector<string> u(m, string(n, '.'));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) u[j][i] = v[i][j];
    if (v == vector<string>(n, string(m, 'P'))) {
      smart_io::precall_print();
      cout, "MORTAL";
      continue;
    }
    if (v == vector<string>(n, string(m, 'A'))) {
      smart_io::precall_print();
      cout, 0;
      continue;
    }
    if (v[0] == string(m, 'A') || v.back() == string(m, 'A') ||
        u[0] == string(n, 'A') || u.back() == string(n, 'A')) {
      smart_io::precall_print();
      cout, 1;
      continue;
    }
    int rez = 4;
    for (int i = 0; i < n; i++) {
      if (v[i] == string(m, 'A')) {
        rez = min(rez, 2);
      }
    }
    for (int i = 0; i < m; i++) {
      if (u[i] == string(n, 'A')) {
        rez = min(rez, 2);
      }
    }
    if (v[0][0] == 'A' || v[n - 1][0] == 'A' || v[0][m - 1] == 'A' ||
        v[n - 1][m - 1] == 'A') {
      rez = min(rez, 2);
    }
    for (int i = 0; i < n; i++) {
      if (v[i][0] == 'A' || v[i][m - 1] == 'A') {
        rez = min(rez, 3);
      }
    }
    for (int i = 0; i < m; i++) {
      if (u[i][0] == 'A' || u[i][n - 1] == 'A') {
        rez = min(rez, 3);
      }
    }
    if (v[0] != string(m, 'P') || v[n - 1] != string(m, 'P')) {
      rez = min(rez, 3);
    }
    if (u[0] != string(n, 'P') || u[m - 1] != string(n, 'P')) {
      rez = min(rez, 3);
    }
    smart_io::precall_print();
    cout, rez;
  }
}
