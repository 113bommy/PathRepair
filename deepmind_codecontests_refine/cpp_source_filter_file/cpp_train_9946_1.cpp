#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double Pi = acos(-1);
bool inline equ(double a, double b) { return fabs(a - b) < EPS; }
int _R(int &x) { return scanf("%d", &x); }
int _R(long long &x) { return scanf("%" PRId64, &x); }
int _R(double &x) { return scanf("%lf", &x); }
int _R(char *s) { return scanf("%s", s); }
int _R(char c) { return scanf("%c", &c); }
int R() { return 0; }
template <typename T, typename... U>
int R(T &x, U &...tail) {
  return _R(x) + R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int N = 3e5 + 10;
const long long INF = 1e16;
int n, m;
vector<int> g[N];
int dep[N];
long long dp[N], inc[N];
set<pair<long long, int> > st[N];
void dfs1(int u, int p) {
  dep[u] = 1 + dep[p];
  dp[u] = INF;
  for (int v : g[u])
    if (v != p) dfs1(v, u);
}
void merge(int u, int v) {
  if ((int)(st[u]).size() < (int)(st[v]).size()) {
    swap(st[u], st[v]);
    swap(inc[u], inc[v]);
  }
  for (auto p : st[v]) {
    long long cst;
    int w;
    tie(cst, w) = p;
    cst = cst + inc[v] - inc[u];
    st[u].insert({cst, w});
  }
  st[v].clear();
}
void dfs2(int u, int p) {
  long long ch_dp = 0;
  for (int v : g[u])
    if (v != p) {
      dfs2(v, u);
      ch_dp += dp[v];
    }
  inc[u] = ch_dp;
  for (int v : g[u])
    if (v != p) {
      inc[v] += ch_dp - dp[v];
      merge(u, v);
    }
  while ((int)(st[u]).size() && dep[st[u].begin()->second] > dep[u] - 1)
    st[u].erase(st[u].begin());
  if ((int)(st[u]).size()) {
    dp[u] = inc[u] + st[u].begin()->first;
  } else {
    puts("-1");
    exit(0);
  }
}
int main() {
  R(n, m);
  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    R(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  g[0].push_back(1);
  dfs1(0, 0);
  for (int i = 0; i < (m); i++) {
    int u, v, c;
    R(u, v, c);
    if (u != v) st[u].insert({c, v});
  }
  st[1].insert({0, 0});
  dfs2(0, 0);
  if (dp[1] >= INF)
    W(-1);
  else
    W(dp[1]);
}
