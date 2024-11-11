#include <bits/stdc++.h>
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
void fast_print(const long long &first) { printf("%lld", first); }
void fast_print(const unsigned long long &first) { printf("%llu", first); }
void fast_print(const double &first) { printf("%.15lf", first); }
void fast_print(const long double &first) { printf("%.15Lf", first); }
void fast_print(const char &first) { printf("%c", first); };
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
void _print(deque<string> names, T kek, Args... args) {
  if (!first_print) {
    fast_print("\n");
  } else {
    first_print = false;
  }
  fast_print(names.front());
  fast_print(" = ");
  fast_print(kek);
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
namespace typedefs {}
namespace numbers_operation {
template <class T>
T floor_mod(T a, T b) {
  if (a % b == 0) return 0;
  if (a >= 0 && b >= 0) return a % b;
  if (a <= 0 && b <= 0) return a % b;
  return abs(b) - (abs(a) % abs(b));
}
}  // namespace numbers_operation
using namespace numbers_operation;
using namespace typedefs;
long long n;
vector<pair<long long, long long>> v;
vector<long double> a;
vector<vector<vector<long double>>> mem;
inline long double dp(long long i, long long pref, long long cur) {
  if (mem[i][pref][cur] != -1e18) return mem[i][pref][cur];
  if (i == n) {
    return 0;
  }
  long double rez = 1e18;
  {
    long long sub_pref = pref;
    long long sub_cur = cur + 1;
    if (i < n - 1 && v[i].first > v[i + 1].first) {
      sub_pref += sub_cur;
      sub_cur = 0;
    }
    rez = min(rez, dp(i + 1, sub_pref, sub_cur) + a[i]);
  }
  if (pref) {
    long long sub_pref = pref - 1;
    long long sub_cur = cur;
    if (i < n - 1 && v[i].first > v[i + 1].first) {
      sub_pref += sub_cur;
      sub_cur = 0;
    }
    rez = min(rez, dp(i + 1, sub_pref, sub_cur));
  }
  return mem[i][pref][cur] = rez;
}
signed main(signed argc, char *argv[]) {
  {
    cin, n;
    v.resize(n);
    for (long long i = 0; i < (n); i++) {
      cin, v[i].first;
    }
    for (long long i = 0; i < (n); i++) {
      cin, v[i].second;
    }
  }
  {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
  }
  {} {} {
    long double left = 0;
    long double right = 1e18;
    for (long long t = 0; t < (200); t++) {
      long double mid = (left + right) / 2;
      long double all = 0;
      a.clear();
      for (long long i = 0; i < (n); i++) {
        a.push_back(v[i].first - mid * v[i].second);
      }
      mem = vector<vector<vector<long double>>>(
          60, vector<vector<long double>>(60, vector<long double>(60, -1e18)));
      all = dp(0, 0, 0);
      if (all > 0) {
        left = mid;
      } else {
        right = mid;
      }
    }
    right *= 1000;
    long long first = right;
    if (right - 0.000000000000001 <= first) {
      smart_io::precall_print();
      cout, first;
    } else {
      smart_io::precall_print();
      cout, first + 1;
    }
  }
}
