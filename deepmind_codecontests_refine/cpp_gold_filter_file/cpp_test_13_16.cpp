#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) {
      os << ',';
    }
    os << v[i];
  }
  os << '}';
  return os;
}
ostream &operator<<(ostream &os, const set<int> &se) {
  os << '{';
  int now = 0;
  for (auto x : se) {
    if (now) {
      os << ',';
    }
    os << x;
    now++;
  }
  os << '}';
  return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &...args) {
  cerr << " " << x;
  debugg(args...);
}
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = 1LL << 61;
const int MAX = 510000;
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
const double pi = acos(-1);
const double eps = 1e-8;
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T>
inline void print(T &a) {
  int sz = a.size();
  for (auto itr = a.begin(); itr != a.end(); itr++) {
    cout << *itr;
    sz--;
    if (sz) cout << " ";
  }
  cout << "\n";
}
template <typename T1, typename T2>
inline void print2(T1 a, T2 b) {
  cout << a << " " << b << "\n";
}
template <typename T1, typename T2, typename T3>
inline void print3(T1 a, T2 b, T3 c) {
  cout << a << " " << b << " " << c << "\n";
}
void mark() {
  cout << "#"
       << "\n";
}
long long pcount(long long x) { return __builtin_popcountll(x); }
const int mod = 998244353;
void solve() {
  string s;
  cin >> s;
  int cnt = 0;
  for (auto c : s)
    if (c == 'B') cnt++;
  if (cnt * 2 == s.size())
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
