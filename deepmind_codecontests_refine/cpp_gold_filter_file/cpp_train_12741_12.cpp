#include <bits/stdc++.h>
using namespace std;
template <typename T>
string to_s(const T& v);
template <>
string to_s(const string& v);
template <>
string to_s(const bool& v);
template <typename T>
string to_s(const vector<T>& v);
template <typename T>
string to_s(const list<T>& v);
template <typename T>
string to_s(const set<T>& v);
template <typename F, typename S>
string to_s(const pair<F, S>& v);
template <typename K, typename V>
string to_s(const map<K, V>& v);
int gcd(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 0 || a == b) return b;
  return gcd(b % a, a);
}
int main(int argc, char* argv[]) {
  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  int g = gcd(a, b);
  a /= g;
  b /= g;
  int k = min(n / a, m / b);
  int w = a * k;
  int h = b * k;
  int ww = w / 2;
  int hh = h / 2;
  int x1 = x - (w - ww);
  int y1 = y - (h - hh);
  int x2 = x + ww;
  int y2 = y + hh;
  if (x1 < 0) {
    x2 -= x1;
    x1 = 0;
  }
  if (x2 > n) {
    x1 -= (x2 - n);
    x2 = n;
  }
  if (y1 < 0) {
    y2 -= y1;
    y1 = 0;
  }
  if (y2 > m) {
    y1 -= (y2 - m);
    y2 = m;
  }
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
template <typename T>
string to_s(const T& v) {
  ostringstream oss;
  oss << v;
  return oss.str();
}
template <>
string to_s(const string& v) {
  ostringstream oss;
  oss << '"' << v << '"';
  return oss.str();
}
template <>
string to_s(const bool& v) {
  ostringstream oss;
  oss << (v ? "true" : "false");
  return oss.str();
}
template <typename T>
string to_s(const vector<T>& v) {
  ostringstream oss;
  oss << "[";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
    oss << to_s(*i) << ",";
  oss << "]";
  return oss.str();
}
template <typename T>
string to_s(const list<T>& v) {
  ostringstream oss;
  oss << "(";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
    oss << to_s(*i) << ",";
  oss << ")";
  return oss.str();
}
template <typename T>
string to_s(const set<T>& v) {
  ostringstream oss;
  oss << "{";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
    oss << to_s(*i) << ",";
  oss << "}";
  return oss.str();
}
template <typename F, typename S>
string to_s(const pair<F, S>& v) {
  ostringstream oss;
  oss << "<" << to_s(v.first) << " " << to_s(v.second) << ">";
  return oss.str();
}
template <typename K, typename V>
string to_s(const map<K, V>& v) {
  ostringstream oss;
  oss << "{";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
    oss << to_s(i->first) << " => " << to_s(i->second) << ",";
  oss << "}";
  return oss.str();
}
