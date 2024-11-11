#include <bits/stdc++.h>
using namespace std;
namespace F {
const int N = 600, M = 400050, inf = ~0u >> 2;
struct edge {
  int t, f, c;
  edge *n, *d;
} eb[M * 2], *ec = eb, *e[N];
int n, s, t, flow, cost;
inline void add_edge(int s, int t, int f, int c) {
  *ec = (edge){t, f, c, e[s], ec + 1};
  e[s] = ec++;
  *ec = (edge){s, 0, -c, e[t], ec - 1};
  e[t] = ec++;
}
inline bool spfa() {
  static int que[M], pre[N], dis[N];
  static edge *pE[N];
  int l(0), r(0), x, y;
  fill(dis, dis + n + 1, inf);
  dis[que[++r] = s] = 0;
  while (l != r)
    for (edge *i = e[x = que[++l]]; i; i = i->n)
      if (i->f && dis[x] + i->c < dis[y = i->t])
        dis[que[++r] = y] = dis[x] + i->c, pre[y] = x, pE[y] = i;
  if (dis[t] > 0) return false;
  int f(inf), c(0);
  for (int i = t; i != s; i = pre[i]) f = min(f, pE[i]->f), c += pE[i]->c;
  for (int i = t; i != s; i = pre[i]) pE[i]->f -= f, pE[i]->d->f += f;
  flow += f;
  cost += f * c;
  return true;
}
inline void solve(int n, int s, int t) {
  F::n = n;
  F::s = s;
  F::t = t;
  while (spfa())
    ;
}
int *idArr;
void dfs(int x, int id) {
  if (x == t) return;
  idArr[(x + 1) / 2] = id;
  for (edge *i = e[x + 1]; i; i = i->n)
    if (i->t > x && i->t != s && !i->f) {
      dfs(i->t, id);
      return;
    }
}
inline void collect(int n, int *id) {
  int cid(0);
  idArr = id;
  for (int i = 1; i <= n; ++i)
    if (!idArr[i]) dfs(i * 2 - 1, ++cid);
}
}  // namespace F
const int N = 255, FF = 16384;
int n, m, arr[N], vID[N];
int genAnswer(bool real = true) {
  static int cval[N];
  int res(0);
  fill(cval, cval + m + 1, -1);
  for (int i = 1; i <= n; ++i) {
    if (cval[vID[i]] != arr[i]) {
      ++res;
      if (real) printf("%c=%d\n", 'a' + vID[i] - 1, arr[i]);
    }
    cval[vID[i]] = arr[i];
    ++res;
    if (real) printf("print(%c)\n", 'a' + vID[i] - 1);
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
  int ss = n * 2 + 1, s = ss + 1, t = s + 1;
  for (int i = 1; i <= n; ++i) {
    F::add_edge(s, (i * 2 - 1), 1, 0);
    F::add_edge((i * 2 - 1), (i * 2), 1, -FF);
    for (int j = i + 1; j <= n; ++j)
      F::add_edge((i * 2), (j * 2 - 1), 1,
                  (arr[i] == arr[j]) ? -__builtin_popcount(arr[j]) : 0);
    F::add_edge((i * 2), t, 1, 0);
  }
  int bres = FF * n;
  for (int i = 1; i <= n; ++i) bres += __builtin_popcount(arr[i]);
  F::add_edge(ss, s, m, 0);
  F::solve(t, ss, t);
  F::collect(n, vID);
  int clines = genAnswer(false);
  printf("%d %d\n", clines, F::cost + bres);
  genAnswer();
  return 0;
}
