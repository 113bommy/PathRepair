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
    fast_print(" ");
    fast_print(v[i]);
  }
}
template <class T>
void fast_print(const vector<vector<T>> &v) {
  if (v.empty()) return;
  fast_print(v[0]);
  for (int i = 1; i < v.size(); i++) {
    fast_print("\n");
    fast_print(v[i]);
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
vector<vector<long long>> nicety;
long long n;
vector<long long> straight_path() {
  vector<long long> dist(n, 1e16);
  vector<bool> checked(n, false);
  long long _min_edge = 2e9;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j) continue;
      _min_edge = min(_min_edge, nicety[i][j]);
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j) continue;
      if (nicety[i][j] == _min_edge) {
        dist[i] = 0;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    long long v = -1;
    for (long long j = 0; j < n; j++) {
      if ((v == -1 || dist[v] > dist[j]) && !checked[j]) {
        v = j;
      }
    }
    if (v == -1) break;
    checked[v] = true;
    for (long long j = 0; j < n; j++) {
      if (j == v) continue;
      if (dist[j] > dist[v] + nicety[v][j] - _min_edge) {
        dist[j] = dist[v] + nicety[v][j] - _min_edge;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    dist[i] += _min_edge * (n - 1);
  }
  return dist;
}
vector<long long> fuzzy_path() {
  vector<long long> dist(n, 1e16);
  vector<bool> checked(n, false);
  long long _min_edge = 2e9;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j) continue;
      _min_edge = min(_min_edge, nicety[i][j]);
    }
  }
  for (long long i = 0; i < n; i++) {
    long long _min = 3e9;
    for (long long j = 0; j < n; j++) {
      if (i == j) continue;
      _min = min(_min, nicety[i][j] - _min_edge);
    }
    dist[i] = _min * 2;
  }
  for (long long i = 0; i < n; i++) {
    long long v = -1;
    for (long long j = 0; j < n; j++) {
      if ((v == -1 || dist[j] > dist[v]) && !checked[j]) v = j;
    }
    if (v == -1) break;
    checked[v] = true;
    for (long long j = 0; j < n; j++) {
      if (v == j) continue;
      if (dist[j] > dist[v] + nicety[v][j] - _min_edge) {
        dist[j] = dist[v] + nicety[v][j] - _min_edge;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    dist[i] += (n - 1) * _min_edge;
  }
  return dist;
}
signed main(signed argc, char *argv[]) {
  cin, n;
  nicety.resize(n, vector<long long>(n, -1));
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      cin, nicety[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (nicety[i][j] == -1) {
        nicety[i][j] = nicety[j][i];
      }
    }
  }
  vector<long long> first = straight_path();
  vector<long long> second = fuzzy_path();
  for (long long i = 0; i < n; i++) {
    smart_io::precall_print();
    cout, second[i];
  }
}
