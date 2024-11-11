#include <bits/stdc++.h>
using namespace std;
long long pow(long long b, long long e, long long m) {
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
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if (m == 3) {
    if (n == 3) {
      cout << "0 0" << endl << "1 1" << endl << "1 0" << endl;
    } else if (n == 4) {
      cout << "0 0" << endl
           << "0 1" << endl
           << "-1 -1" << endl
           << "1 -1" << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  const int X = 1e7;
  for (int i = 1; i <= n; ++i) {
    cout << i << " " << +(X + i * i) << endl;
  }
  for (int i = 1; i <= n - m; ++i) {
    cout << i << " " << -(X + i * i) << endl;
  }
  return 0;
}
