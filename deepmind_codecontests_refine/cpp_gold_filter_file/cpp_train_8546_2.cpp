#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, next, opt;
  long long fl;
} g[4200000];
int ed, st[5200];
vector<int> ans;
inline void add(int x, int y, long long z) {
  ed++;
  g[ed].to = y;
  g[ed].next = st[x];
  g[ed].fl = z;
  st[x] = ed;
  g[ed].opt = ed + 1;
  ed++;
  g[ed].to = x;
  g[ed].next = st[y];
  g[ed].fl = 0;
  st[y] = ed;
  g[ed].opt = ed - 1;
}
const long long inf = (long long)1e16;
const long long bigint = (long long)1e9;
int lev[5200];
int S, x1, T, sta[5200], stp, fr[5200], stae[5200], n, m, x2, x3, x4, val[5200];
long long maxflow, del;
inline bool makelev() {
  queue<int> q;
  q.push(S);
  memset(lev, -1, sizeof(lev));
  lev[S] = 1;
  while (!q.empty()) {
    x1 = q.front();
    q.pop();
    for (int i = st[x1]; i != 0; i = g[i].next) {
      if (g[i].fl != 0 && lev[g[i].to] == -1) {
        lev[g[i].to] = lev[x1] + 1;
        q.push(g[i].to);
        if (g[i].to == T) return true;
      }
    }
  }
  return false;
}
inline void extend() {
  for (int i = S; i <= T; i++) {
    fr[i] = st[i];
  }
  stp = 1;
  sta[1] = S;
  while (stp != 0) {
    x1 = sta[stp];
    if (x1 == T) {
      del = (long long)1e16;
      for (int i = stp; i >= 2; i--) {
        del = min(del, g[stae[i]].fl);
      }
      maxflow += del;
      for (int i = stp; i >= 2; i--) {
        g[stae[i]].fl -= del;
        g[g[stae[i]].opt].fl += del;
        if (g[stae[i]].fl == 0) stp = i - 1;
      }
    } else {
      for (; fr[x1] != 0; fr[x1] = g[fr[x1]].next) {
        if (g[fr[x1]].fl != 0 && lev[g[fr[x1]].to] == lev[x1] + 1) {
          break;
        }
      }
      if (fr[x1] == 0) {
        lev[x1] = -1;
        stp--;
      } else {
        stp++;
        stae[stp] = fr[x1];
        sta[stp] = g[fr[x1]].to;
      }
    }
  }
}
inline void dinic() {
  maxflow = 0;
  while (makelev()) {
    extend();
  }
}
inline long long maxweightclosure() {
  long long tot = 0;
  for (int i = 1; i <= n + n; i++) {
    if (val[i] > 0) {
      tot += val[i];
      add(S, i, val[i]);
    } else {
      add(i, T, -val[i]);
    }
  }
  dinic();
  return tot - maxflow;
}
int main() {
  scanf("%d", &n);
  S = 0;
  T = n + n + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &x1);
      add(i, x1 + n, inf);
    }
  }
  for (int i = 1; i <= n; i++) {
    val[i] = bigint;
    val[i + n] = -bigint;
    scanf("%d", &x1);
    val[i] -= x1;
  }
  printf("%I64d\n", -maxweightclosure());
  return 0;
}
