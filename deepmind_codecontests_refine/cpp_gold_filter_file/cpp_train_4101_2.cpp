#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T x, T y) {
  for (T t; x; t = x, x = y % x, y = t)
    ;
  return y;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  int n, k;
  vector<unsigned int> v;
  cin >> n >> k;
  for (int _end_ = (n), i = (1); i <= _end_; ++i) {
    unsigned int a, b, c, d;
    char S;
    cin >> a >> S >> b >> S >> c >> S >> d;
    v.push_back(a << 24 | b << 16 | c << 8 | d);
  }
  for (int _end_ = (1), i = (31); i >= _end_; --i) {
    map<unsigned int, int> f;
    unsigned int mask = -1u << i;
    for (auto &x : v) {
      ++f[mask & x];
    }
    if ((int)((f).size()) == k) {
      cout << (mask >> 24 & 255) << "." << (mask >> 16 & 255) << "."
           << (mask >> 8 & 255) << "." << (mask & 255) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
