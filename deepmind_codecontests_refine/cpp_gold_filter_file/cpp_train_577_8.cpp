#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > T;
bool done;
void answer(int u) {
  printf("! %d\n", u);
  fflush(stdout);
  done = true;
}
int cnt;
void query(int u) {
  if (T[u].size() > 0) return;
  cnt++;
  printf("? %d\n", u);
  fflush(stdout);
  int k;
  scanf("%d", &(k));
  if (!k) exit(0);
  for (int i = 1, __R = k; i <= __R; i++) {
    int t;
    scanf("%d", &(t));
    T[u].push_back(t);
  }
  if (k == 2) answer(u);
}
int par[128];
vector<bool> vis;
pair<int, int> dive(int u, int p, int d) {
  par[u] = p;
  vis[u] = true;
  query(u);
  if (done) return pair<int, int>();
  for (int v : T[u])
    if (v != p) return dive(v, u, d + 1);
  return pair<int, int>(u, d);
}
int climb(int u, int d) { return d == 0 ? u : climb(par[u], d - 1); }
void dfs(int u, int p, int lim, int d = 0) {
  if (cnt == 16) {
    answer(u);
    return;
  }
  query(u);
  if (done || d == lim) return;
  for (int v : T[u])
    if (v != p) {
      dfs(v, u, lim, d + 1);
      if (done) return;
    }
}
int main() {
  int t;
  scanf("%d", &(t));
  for (int __ = 1, __R = t; __ <= __R; __++) {
    T = vector<vector<int> >(128);
    vis = vector<bool>(128, false);
    done = false;
    cnt = 0;
    int h;
    scanf("%d", &(h));
    if (!h) exit(0);
    query(1);
    if (done) continue;
    vis[1] = true;
    int hei, lca;
    if (T[1].size() == 1) {
      auto l = dive(T[1][0], 1, 1);
      if (done) continue;
      hei = (l.second >> 1) + 1;
      lca = climb(l.first, hei - 1);
    } else {
      auto l1 = dive(T[1][0], 1, 1);
      if (done) continue;
      auto l2 = dive(T[1][1], 1, 1);
      if (done) continue;
      if (l2.second > l1.second) swap(l1, l2);
      hei = ((l1.second + l2.second) >> 1) + 1;
      lca = climb(l1.first, hei - 1);
    }
    while (!done && hei < 4) {
      for (int v : T[lca])
        if (!vis[v]) {
          auto l = dive(v, lca, hei);
          if (!done) {
            hei = (l.second >> 1) + 1;
            lca = climb(l.first, hei - 1);
          }
          break;
        }
    }
    if (done) continue;
    for (int v : T[lca])
      if (!vis[v]) {
        dfs(v, lca, h - (hei + 1));
        break;
      }
  }
  return 0;
}
