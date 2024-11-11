#include <bits/stdc++.h>
const int _ML = 400;
const char _inpf[] = "";
const char _outf[] = "";
#pragma GCC optimize("O3,no-stack-protector")
using namespace std;
const double PI = 3.14159265358979323846;
mt19937 rd(228);
template <class T, class U>
inline ostream &operator<<(ostream &, const pair<T, U> &);
template <class T, class U>
inline istream &operator>>(istream &, pair<T, U> &);
template <class T>
inline ostream &operator<<(ostream &, const vector<T> &);
template <class T>
inline istream &operator>>(istream &, vector<T> &);
template <class T>
inline ostream &operator<<(ostream &, const set<T> &);
template <class T>
inline ostream &operator<<(ostream &, const multiset<T> &);
template <class T>
inline ostream &operator<<(ostream &, const unordered_set<T> &);
template <class T>
inline ostream &operator<<(ostream &, const unordered_multiset<T> &);
template <class T, class U>
inline ostream &operator<<(ostream &, const map<T, U> &);
template <class T, class U>
inline ostream &operator<<(ostream &, const unordered_map<T, U> &);
const long long D = 24 * 60 * 60;
bool ok(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first > b.first) {
    swap(a, b);
  }
  return abs(a.first - b.first) <= D || abs(a.second - b.first) <= D ||
         abs(a.second - b.second) <= D ||
         (a.first <= b.first && b.first <= a.second);
}
long long f(int second, int m, int d, int hh, int mm) {
  tm t = {0};
  t.tm_year = second;
  t.tm_mon = m - 1;
  t.tm_mday = d;
  t.tm_hour = hh;
  t.tm_min = mm;
  return mktime(&t);
}
inline void _main_function() {
  int n;
  cin >> n;
  map<long long, int> m;
  for (int i = 0; i < n; ++i) {
    long long first;
    cin >> first;
    while (m.count(first)) {
      m.erase(first);
      first *= 2;
    }
    m[first] = i;
  }
  vector<pair<int, int>> ans;
  for (auto i : m) {
    ans.push_back({i.second, i.first});
  }
  cout << (int)(ans).size() << '\n';
  sort((ans).begin(), (ans).end());
  for (auto i : ans) {
    cout << i.second << '\n';
  }
}
int main() {
  if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
  if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << setprecision(20);
  _main_function();
}
template <class T, class U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << ' ' << _p.second;
  return _out;
}
template <class T, class U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <class T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) {
    return _out;
  }
  _out << *_v.begin();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <class T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) {
    _in >> _i;
  }
  return _in;
}
template <class T>
inline ostream &operator<<(ostream &_out, const set<T> &_s) {
  if (_s.empty()) {
    return _out;
  }
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <class T>
inline ostream &operator<<(ostream &_out, const multiset<T> &_s) {
  if (_s.empty()) {
    return _out;
  }
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <class T>
inline ostream &operator<<(ostream &_out, const unordered_set<T> &_s) {
  if (_s.empty()) {
    return _out;
  }
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <class T>
inline ostream &operator<<(ostream &_out, const unordered_multiset<T> &_s) {
  if (_s.empty()) {
    return _out;
  }
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <class T, class U>
inline ostream &operator<<(ostream &_out, const map<T, U> &_m) {
  if (_m.empty()) {
    return _out;
  }
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) {
    _out << ", (" << _it->first << ": " << _it->second << ')';
  }
  return _out;
}
template <class T, class U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
  if (_m.empty()) {
    return _out;
  }
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) {
    _out << ", (" << _it->first << ": " << _it->second << ')';
  }
  return _out;
}
