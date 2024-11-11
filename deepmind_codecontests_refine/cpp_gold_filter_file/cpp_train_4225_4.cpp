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
void run() {
  int n, m;
  readln(n, m);
  m = min(m, n * 3);
  int k = n / 2;
  vector<int> a(n), ans(n, -1);
  vector<bool> was(m + 1, false);
  readln(a);
  vector<pair<int, int> > even, odd, tempEven, tempOdd;
  for (int i = 0; i < (int)(n); ++i)
    (a[i] % 2 == 0 ? even : odd).push_back({a[i], i});
  sort(even.rbegin(), even.rend());
  sort(odd.rbegin(), odd.rend());
  int prev__ = -1;
  int last = int(even.size()) - 1;
  for (int i = 0; i < (int)(even.size()); ++i) {
    if (prev__ != even[i].first) tempEven.push_back(even[i]);
    prev__ = even[i].first;
  }
  prev__ = -1;
  last = int(odd.size()) - 1;
  for (int i = 0; i < (int)(odd.size()); ++i) {
    if (prev__ != odd[i].first) tempOdd.push_back(odd[i]);
    prev__ = odd[i].first;
  }
  even = tempEven;
  odd = tempOdd;
  even.resize(min(int(even.size()), k));
  odd.resize(min(int(odd.size()), k));
  for (auto& x : even) {
    ans[x.second] = x.first;
    if (x.first < was.size()) was[x.first] = true;
  }
  for (auto& x : odd) {
    ans[x.second] = x.first;
    if (x.first < was.size()) was[x.first] = true;
  }
  int needsEven = k - even.size();
  int needsOdd = k - odd.size();
  vector<int> indices;
  for (int i = 0; i < (int)(n); ++i)
    if (ans[i] == -1) indices.push_back(i);
  int ANS = indices.size();
  int i = 0;
  for (int k = 1; k < (int)(m + 1); ++k)
    if (!was[k]) {
      if (k % 2 == 0 && needsEven) ans[indices[i++]] = k, needsEven--;
      if (k % 2 == 1 && needsOdd) ans[indices[i++]] = k, needsOdd--;
    }
  if (needsEven + needsOdd == 0)
    writeln(ANS), writeln(ans);
  else
    writeln(-1);
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
