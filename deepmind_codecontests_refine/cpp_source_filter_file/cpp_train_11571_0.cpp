#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void dbg(Args... args) {
  ((cout << args), ...);
}
void f_dbg(int x) { dbg(x); }
void f_dbg(unsigned int x) { dbg(x); }
void f_dbg(long long x) { dbg(x); }
void f_dbg(unsigned long long x) { dbg(x); }
void f_dbg(double x) { dbg(x); }
void f_dbg(long double x) { dbg(x); }
void f_dbg(char x) { dbg(x); }
void f_dbg(string &x) { dbg(x); }
template <size_t N>
void f_dbg(bitset<N> &_t_) {
  for (long long int i = (0); i <= (int(size(_t_)) - 1); ++i) dbg(_t_[i]);
  cout << "\n";
}
template <typename K, typename V>
void f_dbg(pair<K, V> _t_);
template <typename T>
void f_dbg(T(&_t_), int x1 = 0, int x2 = 1e9, string tab = "");
template <typename T, size_t N, size_t M>
void f_dbg(T (&_t_)[N][M], int x1 = 0, int x2 = 1e9, int y1 = 0, int y2 = 1e9,
           string tab = "", string lvl = "");
template <typename T, size_t N, size_t M, size_t K>
void f_dbg(T (&_t_)[N][M][K], int x1 = 0, int x2 = 1e9, int y1 = 0,
           int y2 = 1e9, int z1 = 0, int z2 = 1e9);
template <typename K, typename V>
void f_dbg(map<K, V> &_t_);
template <typename K, typename V>
void f_dbg(pair<K, V> _t_);
template <typename T>
void f_dbg(set<T> _t_);
template <typename T>
void f_dbg(T(&_t_), int x1, int x2, string tab) {
  dbg(tab, "[");
  x2 = min(x2, int(size(_t_)) - 1);
  for (long long int i = (x1); i <= (x2); ++i) {
    dbg(i > x1 ? "," : "");
    f_dbg(_t_[i]);
  }
  dbg("]");
}
template <typename T, size_t N, size_t M>
void f_dbg(T (&_t_)[N][M], int x1, int x2, int y1, int y2, string tab,
           string lvl) {
  dbg(tab, "[");
  x2 = min(x2, int(size(_t_)) - 1);
  for (long long int i = (x1); i <= (x2); ++i) {
    f_dbg(_t_[i], y1, y2, i > x1 ? lvl + " " : "");
    if (i < x2) cout << "\n";
  }
  dbg("]");
}
template <typename T, size_t N, size_t M, size_t K>
void f_dbg(T (&_t_)[N][M][K], int x1, int x2, int y1, int y2, int z1, int z2) {
  dbg("[");
  x2 = min(x2, int(size(_t_)) - 1);
  for (long long int i = (x1); i <= (x2); ++i) {
    f_dbg(_t_[i], y1, y2, z1, z2, i > x1 ? " " : "", " ");
    if (i < x2) cout << "\n";
  }
  dbg("]");
  cout << "\n";
}
template <typename K, typename V>
void f_dbg(map<K, V> &_t_) {
  dbg("[");
  bool beg = 1;
  for (auto &[k, v] : _t_) {
    dbg(!beg ? "," : "", "[");
    beg = 0;
    f_dbg(k);
    dbg(":");
    f_dbg(v);
    dbg("]");
  }
  dbg("]");
}
template <typename K, typename V>
void f_dbg(pair<K, V> _t_) {
  auto &[k, v] = _t_;
  dbg("[");
  f_dbg(k);
  dbg(",");
  f_dbg(v);
  dbg("]");
}
template <typename T>
void f_dbg(set<T> _t_) {
  bool beg = 1;
  dbg("[");
  for (auto &e : _t_) {
    if (!beg) dbg(",");
    beg = 0;
    f_dbg(e);
  }
  dbg("]");
}
long long int inf = 1e18 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, v;
  cin >> n >> v;
  if (v >= n - 1) return cout << min(v, n), 0;
  long long int ans = v, cur = v;
  for (long long int i = (2); i <= (n); ++i) {
    ans += i;
    if (cur + i >= n) break;
  }
  cout << ans;
  return 0;
}
