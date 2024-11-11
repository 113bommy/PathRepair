#include <bits/stdc++.h>
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << " " << _p.second;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) return _out;
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) _in >> _i;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_set<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const unordered_multiset<T> &_s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << "{\"" << _m.begin()->first << "\", \"" << _m.begin()->second << "\"}";
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", { \"" << _it->first << "\", \"" << _it->second << "\"}";
  return _out;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->first << ": " << _it->second << ')';
  return _out;
}
template <typename T>
void out(const vector<T> &a, int n) {
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << "\n";
}
template <typename T>
void out(const vector<vector<T>> &a, int n, int m) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
vector<vector<pair<int, int>>> v;
vector<int> lg;
void dfs(int i, int par = -1) {
  for (auto [j, w] : v[i]) {
    if (j == par) continue;
    dfs(j, i);
    lg[i] = max(lg[i], lg[j] + w);
  }
}
void solve() {
  int n;
  cin >> n;
  v.resize(n + 1), lg.resize(n + 1);
  int su = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    su += c, v[a].emplace_back(b, c), v[b].emplace_back(a, c);
  }
  dfs(1);
  cout << 2LL * su - *max_element(lg.begin(), lg.end());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  startTime = clock();
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
