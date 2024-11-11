#include <bits/stdc++.h>
using namespace std;
namespace Debug {
void __print(signed x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
}  // namespace Debug
using namespace Debug;
template <typename Arg1>
void p(Arg1 &&arg1) {
  cout << arg1;
}
template <typename Arg1, typename... Args>
void p(Arg1 &&arg1, Args &&...args) {
  cout << arg1;
  p(args...);
}
template <typename Arg1>
void read(Arg1 &&arg1) {
  cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1 &&arg1, Args &&...args) {
  cin >> arg1;
  read(args...);
}
const bool DEBUG = true;
void process() {
  long long x, y;
  read(x, y);
  if (2ll * x > y) {
    cout << "-1 -1\n";
  } else {
    cout << x << " " << (2ll * x) << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    process();
  }
  return 0;
}
