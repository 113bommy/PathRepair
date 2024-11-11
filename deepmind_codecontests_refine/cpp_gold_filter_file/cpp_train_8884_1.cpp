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
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 1100000;
struct node {
  bool can[4];
};
string::iterator ptr;
int run(char type, int x, int y) {
  if (type == '&') return x & y;
  if (type == '^') return x ^ y;
  if (type == '|') return x | y;
  return assert(0), -1;
}
node build() {
  node t = (node){{0}};
  if (*ptr != '(') {
    t.can[0] = *ptr == '0';
    t.can[3] = *ptr == '1';
    t.can[1] = t.can[2] = *ptr == '?';
    return ++ptr, t;
  }
  ++ptr;
  node lc = build();
  char type = *ptr;
  ++ptr;
  node rc = build();
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (lc.can[i] && rc.can[j])
        t.can[run(type, i >> 1, j >> 1) << 1 | run(type, i & 1, j & 1)] = true;
  return ++ptr, t;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string S;
  cin >> n >> S;
  ptr = S.begin();
  auto root = build();
  cout << (root.can[1] | root.can[2] ? "YES" : "NO") << endl;
  return 0;
}
