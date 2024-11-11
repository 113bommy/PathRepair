#include <bits/stdc++.h>
using namespace std;
int an, n, a[200005], sz[200005];
vector<pair<int, int> > Ed[200005];
double Ans = 1e20, sm, d[200005];
bool bo[200005];
inline int IN() {
  char c;
  register int first = 0;
  for (; (c = getchar()) < 48 && c ^ '-' || c > 57;)
    ;
  bool f = c == '-';
  if (f) (c = getchar());
  for (; c > 47 && c < 58; (c = getchar())) first = first * 10 + c - 48;
  if (f) first = -first;
  return first;
}
int gsz(int u, int ff = 0) {
  for (pair<int, int> X : Ed[u])
    if (X.first ^ ff) sz[u] += gsz(X.first, u);
  return ++sz[u];
}
int grt(int u) {
  int maxx = 0, w;
  for (pair<int, int> W : Ed[u])
    if (!bo[W.first] && sz[W.first] > maxx) maxx = sz[W.first], w = W.first;
  if (maxx * 2 > sz[u]) {
    sz[u] -= sz[w];
    sz[w] += sz[u];
    return grt(w);
  }
  return u;
}
void dfs(int u, int ff = 0) {
  sm += a[u] * d[u] * sqrt(d[u]);
  for (pair<int, int> W : Ed[u]) {
    int v = W.first;
    if (v ^ ff) {
      d[v] = d[u] + W.second;
      dfs(v, u);
    }
  }
}
inline void gao(int u) {
  d[u] = sm = 0;
  dfs(u);
  if (sm < Ans) Ans = sm, an = u;
}
void dfss(int u, int ff) {
  sm += a[u] * sqrt(d[u]);
  for (pair<int, int> W : Ed[u]) {
    int v = W.first;
    if (v ^ ff) {
      d[v] = d[u] + W.second;
      dfss(v, u);
    }
  }
}
inline double calc(int v, int jb, int u) {
  d[v] = jb;
  sm = 0;
  dfss(v, u);
  return sm;
}
void dc(int u) {
  bo[u = grt(u)] = 1;
  gao(u);
  int w = 0;
  double ma = -1e10;
  for (pair<int, int> W : Ed[u]) {
    int v = W.first;
    if (!bo[v]) {
      double jb = calc(v, W.second, u);
      if (jb > ma) ma = jb, w = v;
    }
  }
  if (w) dc(w);
}
int main() {
  n = IN();
  for (int _r = n, i = 1; i <= _r; ++i) a[i] = IN();
  for (int _r = n, i = 1; i < _r; ++i) {
    int u = IN(), v = IN(), w = IN();
    Ed[u].push_back({v, w});
    Ed[v].push_back({u, w});
  }
  gsz(1);
  dc(1);
  printf("%d %.20lf\n", an, Ans);
}
