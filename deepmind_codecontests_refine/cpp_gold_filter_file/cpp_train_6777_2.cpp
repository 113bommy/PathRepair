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
void fast_print(const unsigned int &first) { printf("%u", first); }
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
namespace std::chrono {
long long get_time_ms() {
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}
};  // namespace std::chrono
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
template <class T>
T gcd(T __m, T __n) {
  while (__n != 0) {
    T __t = __m % __n;
    __m = __n;
    __n = __t;
  }
  return __m;
}
const long long MOD = 998244353;
long long n;
vector<long long> v;
map<long long, long long> oaethusoaetuhs;
long long sqrt3(long long n) {
  long long rez = cbrt(n);
  while (rez * rez * rez < n) rez++;
  while (rez * rez * rez > n) rez--;
  return rez;
}
long long sqrt2(long long n) {
  long long rez = sqrt(n);
  while (rez * rez < n) rez++;
  while (rez * rez > n) rez--;
  return rez;
}
long long sqrt4(long long n) {
  long long rez = sqrt(sqrt(n));
  while (rez * rez * rez * rez < n) rez++;
  while (rez * rez * rez * rez > n) rez--;
  return rez;
}
signed main(signed argc, char *argv[]) {
  cin, n;
  v.resize(n);
  cin, v;
  vector<long long> b;
  for (long long first : v) {
    long long cb = sqrt3(first);
    long long two = sqrt2(first);
    long long four = sqrt4(first);
    if (four * four * four * four == first) {
      oaethusoaetuhs[four] += 4;
    } else if (cb * cb * cb == first) {
      oaethusoaetuhs[cb] += 3;
    } else if (two * two == first) {
      oaethusoaetuhs[two] += 2;
    } else {
      b.push_back(first);
    }
  }
  map<long long, long long> junk;
  long long rez = 1;
  for (long long first : b) {
    bool found = false;
    for (long long second : v) {
      long long g = gcd(first, second);
      if (g != first && g != 1) {
        oaethusoaetuhs[first / g]++;
        oaethusoaetuhs[g]++;
        found = true;
        break;
      }
    }
    if (!found) {
      junk[first]++;
    }
  }
  for (auto p : oaethusoaetuhs) {
    rez *= p.second + 1;
    rez %= MOD;
  }
  for (auto p : junk) {
    rez *= p.second + 1;
    rez %= MOD;
    rez *= p.second + 1;
    rez %= MOD;
  }
  smart_io::precall_print();
  cout, rez;
}
