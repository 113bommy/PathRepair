#include <bits/stdc++.h>
using namespace std;
const int N = 301010;
int n, m, i, f[N], flag[N], tot, deep[N], A, B;
long long ans;
struct gg {
  int p, id, v;
} jump[N][20];
vector<pair<int, int> > edge[N];
struct g {
  int a, b, l, r, id;
} e[N], ee[N];
bool cmp(g u, g v) { return u.a < v.a; }
int gf(int x) {
  int p = x, t;
  while (p != f[p]) p = f[p];
  while (x != p) {
    t = f[x];
    f[x] = p;
    x = t;
  }
  return p;
}
void dfs(int x, int fa, int id) {
  int i;
  deep[x] = deep[fa] + 1;
  jump[x][0].p = fa;
  jump[x][0].v = ee[id].a;
  jump[x][0].id = id;
  for (i = 1; i <= 18; i++) {
    jump[x][i].p = jump[jump[x][i - 1].p][i - 1].p;
    if (jump[x][i - 1].v < jump[jump[x][i - 1].p][i - 1].v) {
      jump[x][i].v = jump[jump[x][i - 1].p][i - 1].v;
      jump[x][i].id = jump[jump[x][i - 1].p][i - 1].id;
    } else {
      jump[x][i].v = jump[x][i - 1].v;
      jump[x][i].id = jump[x][i - 1].id;
    }
  }
  for (i = 0; i < edge[x].size(); i++)
    if (edge[x][i].first != fa) dfs(edge[x][i].first, x, edge[x][i].second);
}
pair<int, int> get(int a, int b) {
  int i, ans = 0, Ans;
  if (deep[a] < deep[b]) swap(a, b);
  for (i = 18; i >= 0; i--)
    if (deep[jump[a][i].p] >= deep[b]) {
      if (jump[a][i].v > ans) {
        ans = jump[a][i].v;
        Ans = jump[a][i].id;
      }
      a = jump[a][i].p;
    }
  if (a == b) return make_pair(ans, Ans);
  for (i = 18; i >= 0; i--)
    if (jump[a][i].p != jump[b][i].p) {
      if (jump[a][i].v > ans) {
        ans = jump[a][i].v;
        Ans = jump[a][i].id;
      }
      if (jump[b][i].v > ans) {
        ans = jump[b][i].v;
        Ans = jump[b][i].id;
      }
      a = jump[a][i].p;
      b = jump[b][i].p;
    }
  if (jump[a][0].v > ans) {
    ans = jump[a][0].v;
    Ans = jump[a][0].id;
  }
  if (jump[b][0].v > ans) {
    ans = jump[b][0].v;
    Ans = jump[b][0].id;
  }
  return make_pair(ans, Ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d", &e[i].a);
  for (i = 1; i <= m; i++) scanf("%d", &e[i].b);
  for (i = 1; i <= m; i++) scanf("%d%d", &e[i].l, &e[i].r), e[i].id = i;
  scanf("%d", &tot);
  for (i = 1; i <= m; i++) ee[i] = e[i];
  sort(e + 1, e + 1 + m, cmp);
  for (i = 1; i <= n; i++) f[i] = i;
  for (i = 1; i <= m; i++) {
    int u = gf(e[i].l);
    int v = gf(e[i].r);
    if (u != v) {
      f[u] = v;
      edge[e[i].l].push_back(make_pair(e[i].r, e[i].id));
      edge[e[i].r].push_back(make_pair(e[i].l, e[i].id));
      ans = ans + e[i].a;
      flag[e[i].id] = 1;
    }
  }
  dfs(1, 0, 0);
  long long Ans = 1LL << 50;
  for (i = 1; i <= m; i++) {
    pair<int, int> tmp1 = get(ee[i].l, ee[i].r);
    long long tmp2 = ans - tmp1.first + ee[i].a - tot / ee[i].b;
    if (tmp2 < Ans) {
      Ans = tmp2;
      A = i;
      B = tmp1.second;
    }
  }
  printf("%I64d\n", Ans);
  flag[B] = 0;
  flag[A] = 1;
  for (i = 1; i <= m; i++)
    if (flag[i]) {
      if (i == A)
        printf("%d %d\n", i, ee[i].a - tot / ee[i].b);
      else
        printf("%d %d\n", i, ee[i].a);
    }
}
