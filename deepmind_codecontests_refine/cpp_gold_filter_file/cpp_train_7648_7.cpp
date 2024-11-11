#include <bits/stdc++.h>
using namespace std;
inline void writeln2() { cout << "\n"; }
inline void writeln() { cout << "\n"; }
inline void readln() {}
template <typename T>
inline void read(T&);
template <typename T>
inline void priws(T);
template <typename T>
inline void print(T);
void err(vector<string>::iterator it) { ++it; }
template <typename Head, typename... Tail>
inline void readln(Head& head, Tail&... tail) {
  read(head);
  readln(tail...);
}
template <typename Head, typename... Tail>
inline void writeln2(Head head, Tail... tail) {
  print(head);
  writeln2(tail...);
}
template <typename Head, typename... Tail>
inline void writeln(Head head, Tail... tail) {
  priws(head);
  writeln2(tail...);
}
template <typename T>
inline void writeln_range(T f, T s) {
  if (f != s)
    for (auto i = f; i != s; ++i) writeln(*i);
}
template <typename Head, typename... Tail>
inline void err(vector<string>::iterator it, Head head, Tail... tail) {
  writeln((*it).substr((*it)[0] == ' '), "=", head);
  err(++it, tail...);
}
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.push_back(x);
  return move(v);
}
void run() {
  int n, T;
  double c;
  readln(n, T, c);
  vector<int> a(n);
  readln(a);
  vector<int> p;
  readln(p);
  int m = p.size();
  int j = 0;
  double real = 0;
  double app = 0;
  long long sum = 0;
  cout.precision(6);
  for (int i = 0; i < (int)(n); ++i) {
    if (j == m) break;
    sum += a[i];
    if (i >= T) sum -= a[i - T];
    real = (0.0 + sum) / T;
    app = (app + (0.0 + a[i]) / T) / c;
    if (p[j] == i + 1)
      j++, cout << fixed << real << " " << app << " " << fabs(app - real) / real
                << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  run();
  return 0;
}
template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& _a);
template <typename T1, typename T2>
inline istream& operator>>(istream& is, pair<T1, T2>& _a) {
  return is >> _a.first >> _a.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, pair<T1, T2>& _a) {
  return os << _a.first << " " << _a.second;
}
template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& _a) {
  if (_a.size())
    os << _a[0];
  else
    os << "\n";
  for (int i = 1; i < _a.size(); ++i)
    os << "\n "[is_fundamental<T>::value] << _a[i];
  return os;
}
template <typename T>
inline istream& operator>>(istream& is, vector<T>& _a) {
  if (_a.size() == 0) {
    int _n;
    is >> _n;
    _a.resize(_n);
  }
  for (int i = 0; i < _a.size(); ++i) is >> _a[i];
  return is;
}
template <typename T>
inline void print(T _a) {
  cout << " " << _a;
}
template <typename T>
inline void priws(T _a) {
  cout << _a;
}
template <typename T>
inline void read(T& _a) {
  cin >> _a;
}
