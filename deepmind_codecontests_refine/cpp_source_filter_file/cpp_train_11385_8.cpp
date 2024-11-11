#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
  pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
inline pt operator-(const pt &p1, const pt &p2) {
  return pt(p1.x - p2.x, p1.y - p2.y);
}
inline bool operator<(const pt &p1, const pt &p2) {
  return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
}
inline long long operator^(const pt &p1, const pt &p2) {
  return (long long)p1.x * p2.y - (long long)p1.y * p2.x;
}
const int maxn = (int)1e5;
pt ps[maxn];
inline int sign(int x) { return x < 0 ? -1 : !!x; }
inline int type(const pt &p) {
  assert(p.x || p.y);
  if (!p.y) return p.x > 0 ? 0 : 2;
  return p.y > 0 ? 1 : 3;
}
pt Pcomp;
inline bool compare(const int a, const int b) {
  if (type(ps[a] - Pcomp) != type(ps[b] - Pcomp))
    return type(ps[a] - Pcomp) < type(ps[b] - Pcomp);
  return ((ps[a] - Pcomp) ^ (ps[b] - Pcomp)) > 0;
}
vector<vector<int> > es, cs, prec;
bool used[maxn];
int dfs(int v, int pr) {
  used[v] = 1;
  int res = 1;
  for (int it = 0; it < ((int)(es[v]).size()); it++) {
    int u = es[v][it];
    if (used[u]) continue;
    int curr = dfs(u, v);
    res += curr;
    cs[v][it] -= curr;
  }
  for (int it = 0; it < ((int)(es[v]).size()); it++) {
    int u = es[v][it];
    if (u == pr) cs[v][it] += res;
  }
  return res;
}
int cyc[maxn];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    n++;
    es = vector<vector<int> >(n);
    for (int i = 0; i < m; i++) {
      int s, t;
      scanf("%d%d", &s, &t);
      s--, t--;
      es[s].push_back(t);
      es[t].push_back(s);
    }
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &ps[i].x, &ps[i].y);
    }
    {
      int mni = min_element(ps, ps + n - 1) - ps;
      ps[n - 1] = ps[mni], ps[n - 1].x--;
      es[n - 1].push_back(mni);
      es[mni].push_back(n - 1);
    }
    for (int i = 0; i < n; i++) {
      Pcomp = ps[i];
      sort(es[i].begin(), es[i].end(), compare);
    }
    cs = vector<vector<int> >(n);
    for (int i = 0; i < n; i++) cs[i] = vector<int>(((int)(es[i]).size()), 0);
    memset(used, 0, sizeof(used));
    dfs(n - 1, -1);
    prec = vector<vector<int> >(n);
    for (int i = 0; i < n; i++) {
      prec[i].resize(((int)(es[i]).size()) + 1);
      prec[i][0] = 0;
      for (int j = 0; j < ((int)(es[i]).size()); j++)
        prec[i][j + 1] = prec[i][j] + cs[i][j];
    }
    int maxq;
    scanf("%d", &maxq);
    for (int q = 0; q < maxq; q++) {
      int len;
      scanf("%d", &len);
      for (int i = 0; i < len; i++) scanf("%d", &cyc[i]), cyc[i]--;
      long long S = 0;
      for (int i = 0; i < len; i++)
        S += (cyc[i] ^ cyc[i == len - 1 ? 0 : i + 1]);
      if (S < 0) reverse(cyc, cyc + len), S = -S;
      int ans = 0;
      for (int iter = 0; iter < len; iter++) {
        int v = cyc[iter];
        Pcomp = ps[v];
        int prev = cyc[iter ? iter - 1 : len - 1],
            next = cyc[iter == len - 1 ? 0 : iter + 1];
        int itprev = lower_bound(es[v].begin(), es[v].end(), prev, compare) -
                     es[v].begin();
        int itnext = lower_bound(es[v].begin(), es[v].end(), next, compare) -
                     es[v].begin();
        assert(itprev < ((int)(es[v]).size()) &&
               itnext < ((int)(es[v]).size()));
        assert(!compare(es[v][itprev], prev) && !compare(prev, es[v][itprev]));
        assert(!compare(es[v][itnext], next) && !compare(next, es[v][itnext]));
        int res = prec[v][itprev + 1] - prec[v][itnext];
        if (itprev < itnext) res += prec[v][((int)(prec[v]).size()) - 1];
        res = prec[v][((int)(prec[v]).size()) - 1] - res;
        ans += res;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
