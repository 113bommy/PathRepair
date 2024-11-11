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
  return v;
}
template <typename T>
inline void printAnswerAndExit(T a) {
  writeln(a);
  exit(0);
}
void run() {
  int s, x1, x2, t1, t2, p, d;
  readln(s, x1, x2, t1, t2, p, d);
  int ans = abs(x1 - x2) * t2;
  if (t2 <= t1) printAnswerAndExit(ans);
  if (x1 < x2) {
    if (p > x1 && d > 0) p = -s - s + p;
    if (d < 0) p = -p;
  } else {
    if (p < x1 && d < 0) p = s + p + p;
    if (d > 0) p = s + s - p;
  }
  ans = min(ans, abs(x2 - p) * t1);
  writeln(ans);
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
inline ostream& operator<<(ostream& os, valarray<T>& _a) {
  if (_a.size())
    os << _a[0];
  else
    os << "\n";
  for (int i = 1; i < _a.size(); ++i)
    os << "\n "[is_fundamental<T>::value] << _a[i];
  return os;
}
template <typename T>
inline istream& operator>>(istream& is, valarray<T>& _a) {
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
