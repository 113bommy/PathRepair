#include <bits/stdc++.h>
using namespace std;
namespace std {
string to_string(string const& s) { return '"' + s + '"'; }
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <class T1, class T2>
string to_string(pair<T1, T2> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class T>
string to_string(T c) {
  string s = "[";
  for (auto vvv : c) {
    s += to_string(vvv) + ",";
  }
  s += "]";
  return s;
}
void debug_impl() { cerr << endl; };
template <typename T1, typename... T2>
void debug_impl(T1 a, T2... b) {
  cerr << " " << to_string(a);
  debug_impl(b...);
}
}  // namespace std
int gcd(int a, int b) {
  while (a && b)
    if (a > b)
      a %= b;
    else
      b %= a;
  return a + b;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    double a, b;
    cin >> a >> b;
    double res;
    if (a == 0) {
      res = 0.5;
    } else if (b == 0) {
      res = 1;
    } else if (4 * b >= a) {
      res = a * b + a * a / 8;
      res /= 2 * a * b;
    } else {
      res = a * b + b * (2 * a - 4 * b) / 2;
      res /= 2 * a * b;
    }
    printf("%.15lf\n", res);
  }
  return 0;
}
