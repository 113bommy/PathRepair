#include <bits/stdc++.h>
#pragma GCC optimize "-oFast"
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
const int MAXN = 1000228;
int n, m;
int d[MAXN], p[MAXN], h[MAXN], used[MAXN];
vector<int> g[MAXN];
vector<int> ans;
int v[MAXN], kk[MAXN];
int c;
void dfs1(int u) {
  if (v[u] != -1) {
    return;
  }
  c++;
  v[u] = 0;
  for (auto h : g[u]) {
    dfs1(h);
  }
}
void dfs2(int u) {
  if (v[u] != 0) {
    return;
  }
  v[u] = c;
  for (auto h : g[u]) {
    dfs2(h);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    d[i] = n * 2 + 4;
    p[i] = -1;
    v[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (auto i : g[n - 1]) {
    h[i] = -1;
  }
  int ks = 0;
  d[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    ks++;
    for (auto i : g[a]) {
      if (d[i] > n) {
        d[i] = d[a] + 1;
        p[i] = a;
        q.push(i);
      }
    }
  }
  v[0] = ks;
  for (int i = 0; i < n; i++) {
    if (v[i] != -1) {
      continue;
    }
    c = 0;
    dfs1(i);
    c++;
    dfs2(i);
  }
  for (int k = 0; k < n; k++) {
    if (d[k] > n || (int)(g[k]).size() == v[k] - 1) {
      continue;
    }
    if (h[k]) {
      break;
    }
    int t = d[k];
    if (t + 4 > d[n - 1]) {
      break;
    }
    used[k] = 1;
    for (auto i : g[k]) {
      used[i] = 1;
    }
    for (auto i : g[k]) {
      if (i == 0) {
        continue;
      }
      for (auto j : g[i]) {
        if (j == 0) {
          continue;
        }
        if (used[j]) {
          continue;
        }
        cout << t + 4 << '\n';
        if (t > 0) {
          cout << 1 << ' ';
        }
        cout << k + 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << ' '
             << n << '\n';
        return 0;
      }
    }
    break;
  }
  if (d[n - 1] > n) {
    cout << -1;
    return 0;
  }
  int a = n - 1;
  while (a != -1) {
    ans.push_back(a);
    a = p[a];
  }
  reverse((ans).begin(), (ans).end());
  cout << (int)(ans).size() - 1 << '\n';
  for (auto i : ans) {
    cout << i + 1 << ' ';
  }
  return 0;
}
