#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << ' ' << _p.second;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) {
    return _out;
  }
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) {
    _in >> _i;
  }
  return _in;
}
template <typename T>
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
template <typename T>
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
template <typename T>
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
template <typename T>
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
template <typename T, typename U>
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
template <typename T, typename U>
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
const string FILENAME = "input";
int nans;
int ans[228];
int cur[228];
void solve(const vector<int> &a, int t, int uk) {
  if (uk >= nans) {
    return;
  }
  if (a.empty() || ((int)(a).size() == 1 && a.back() == 0)) {
    nans = uk;
    for (int i = 0; i < uk; i++) {
      ans[i] = cur[i];
    }
  }
  if (t > 18) {
    return;
  }
  vector<int> ones, zeros;
  for (auto first : a) {
    if (abs(first) & 1) {
      ones.push_back((first - 1) / 2);
    } else {
      zeros.push_back(first / 2);
    }
  }
  if (ones.empty()) {
    solve(zeros, t + 1, uk);
    return;
  }
  vector<int> cur;
  cur.resize((int)(ones).size() + (int)(zeros).size());
  merge((ones).begin(), (ones).end(), (zeros).begin(), (zeros).end(),
        cur.begin());
  cur.resize(distance(cur.begin(), unique((cur).begin(), (cur).end())));
  cur[uk] = 1 << t;
  solve(cur, t + 1, uk + 1);
  for (auto &first : ones) {
    first++;
  }
  cur.resize((int)(ones).size() + (int)(zeros).size());
  merge((ones).begin(), (ones).end(), (zeros).begin(), (zeros).end(),
        cur.begin());
  cur.resize(distance(cur.begin(), unique((cur).begin(), (cur).end())));
  cur[uk] = -(1 << t);
  solve(cur, t + 1, uk + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort((a).begin(), (a).end());
  a.resize(distance(a.begin(), unique((a).begin(), (a).end())));
  nans = 0;
  for (int i = 0; i < 18; i++) {
    ans[nans++] = 1 << i;
    ans[nans++] = -(1 << i);
  }
  solve(a, 0, 0);
  cout << nans << '\n';
  for (int i = 0; i < nans; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
