#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;
template <typename T>
using maxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
inline void input(int& _x) {
  _x = 0;
  int _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x = _x * 10 + (_tc - 48), _tc = getchar();
  _x *= _tmp;
}
inline void output(int _x) {
  char _buff[20];
  int _f = 0;
  if (_x == 0) putchar('0');
  while (_x > 0) {
    _buff[_f++] = _x % 10 + '0';
    _x /= 10;
  }
  for (_f -= 1; _f >= 0; _f--) putchar(_buff[_f]);
  putchar('\n');
}
template <typename Iter>
ostream& _out(ostream& s, Iter b, Iter e) {
  s << "[";
  for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
  s << "]";
  return s;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
template <typename T>
ostream& operator<<(ostream& s, const vector<T>& c) {
  return _out(s, c.begin(), c.end());
}
signed main() {
  int64_t n;
  cin >> n;
  int64_t ans = 0, b = 0, w = 0;
  for (int64_t i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    ans += x / 2;
    (i % 2 ? b : w) += x % 2;
  }
  cout << ans + min(b, w) << '\n';
}
