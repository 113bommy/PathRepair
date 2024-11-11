#include <bits/stdc++.h>
using namespace std;
void re(int& x);
template <class T, class... Ts>
void re(T& t, Ts&... ts);
void pr(int x);
void pr(const char* x);
void ps();
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts);
vector<pair<int, int>> edges;
vector<pair<pair<int, int>, int>> g[51];
int pd[151][51][51];
int w[51];
int n, m, s;
int rec(int edge, int totc, int here) {
  if (totc == 0) return 0;
  int v, p;
  if (edge >= (int)(edges).size()) {
    v = edge - (int)(edges).size();
    p = -1;
  } else {
    v = edges[edge].second;
    p = edges[edge].first;
  }
  int& ret = pd[edge][totc][here];
  if (pd[edge][totc][0] == -1) {
    pd[edge][totc][0] = 0;
    bool leaf = ((int)(g[v]).size() <= (p != -1));
    if (leaf) {
      for (int hh = totc; hh >= 1; hh--) {
        pd[edge][totc][hh] = rec(v + (int)(edges).size(), totc - hh, totc - hh);
      }
    }
    for (auto dd : g[v])
      if (dd.first.first != p) {
        int nxt_edge = dd.second;
        int edge_cost = dd.first.second;
        for (int hh = totc; hh >= 1; hh--) {
          for (int left = 0; left <= hh - 1; left++)
            if (pd[edge][totc][left] != -1) {
              int tc = edge_cost + rec(nxt_edge, totc, hh - left);
              if (left) tc = min(tc, pd[edge][totc][left]);
              pd[edge][totc][hh] = max(pd[edge][totc][hh], tc);
            }
        }
      }
  }
  return ret;
}
void dfs(int v, int p) {
  for (auto dd : g[v])
    if (dd.first.first != p) {
      int x = dd.first.first;
      dfs(x, v);
      w[v] += w[x];
    }
}
void solve() {
  memset(pd, -1, sizeof(pd));
  re(n);
  for (int i = 0; i < (n - 1); ++i) {
    int u, v, w;
    re(u, v, w);
    u--;
    v--;
    g[u].push_back({{v, w}, (int)(edges).size()});
    edges.push_back({u, v});
    g[v].push_back({{u, w}, (int)(edges).size()});
    edges.push_back({v, u});
  }
  re(s);
  s--;
  re(m);
  for (int i = 0; i < (m); ++i) {
    int a;
    re(a);
    a--;
    if (a != s) w[a]++;
  }
  dfs(s, -1);
  int ans = 1000000000;
  for (auto dd : g[s]) {
    int x = dd.first.first;
    int nxt_edge = dd.second;
    int edge_cost = dd.first.second;
    if (w[x]) ans = min(ans, edge_cost + rec(nxt_edge, m, w[x]));
  }
  if (ans == 1000000000) ans = 0;
  ps(ans);
}
int main() { solve(); }
void re(int& x) { scanf("%d", &x); }
template <class T, class... Ts>
void re(T& t, Ts&... ts) {
  re(t);
  re(ts...);
}
void pr(int x) { printf("%d", x); }
void pr(const char* x) { printf("%s", x); }
void ps() { pr("\n"); }
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(" ");
  ps(ts...);
}
