#include <bits/stdc++.h>
using namespace std;
int n, m, q, first[500010] = {0}, tot = 0, totke, pos[500010], tim = 0;
int ma[500010], mb[500010], pre[500010][21] = {0}, dep[500010] = {0};
int p[2000010], totp, pe[500010], tote, fa[500010];
int st[500010], top;
long long mw[500010], mx[500010][21] = {0}, dis[500010] = {0};
struct kruskaledge {
  int a, b;
  long long w;
} me[500010];
struct treeedge {
  int v, next;
  long long w;
} e[1000010];
bool cmp(kruskaledge a, kruskaledge b) { return a.w < b.w; }
void insert(int a, int b, long long w) {
  e[++tot].v = b;
  e[tot].next = first[a];
  e[tot].w = w;
  first[a] = tot;
}
int find(int x) {
  int r = x, i = x, j;
  while (r != fa[r]) r = fa[r];
  while (i != r) j = fa[i], fa[i] = r, i = j;
  return r;
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  fa[fx] = fy;
}
long long kruskal(long long init, bool type) {
  long long tot = init;
  sort(me + 1, me + totke + 1, cmp);
  for (int i = 1; i <= totke; i++)
    if (find(me[i].a) != find(me[i].b)) {
      tot += me[i].w;
      merge(me[i].a, me[i].b);
      if (type) {
        insert(me[i].a, me[i].b, me[i].w);
        insert(me[i].b, me[i].a, me[i].w);
      }
    }
  return tot;
}
void dfs(int v) {
  pos[v] = ++tim;
  for (int i = first[v]; i; i = e[i].next)
    if (e[i].v != pre[v][0]) {
      pre[e[i].v][0] = v;
      dep[e[i].v] = dep[v] + 1;
      mx[e[i].v][0] = e[i].w;
      dis[e[i].v] = dis[v] + e[i].w;
      dfs(e[i].v);
    }
}
bool cmpp(int a, int b) { return pos[a] < pos[b]; }
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int i = 20; i >= 0; i--)
    if (dep[pre[a][i]] >= dep[b]) a = pre[a][i];
  if (a == b) return a;
  for (int i = 20; i >= 0; i--)
    if (pre[a][i] != pre[b][i]) a = pre[a][i], b = pre[b][i];
  return pre[a][0];
}
long long findmx(int a, int b) {
  long long ans = 0;
  for (int i = 20; i >= 0; i--)
    if (dep[pre[a][i]] >= dep[b]) {
      ans = max(ans, mx[a][i]);
      a = pre[a][i];
    }
  return ans;
}
void solve() {
  int newp = totp;
  sort(p + 1, p + totp + 1, cmpp);
  for (int i = 1; i < totp; i++) p[++newp] = lca(p[i], p[i + 1]);
  totp = newp;
  sort(p + 1, p + totp + 1, cmpp);
  newp = 0;
  for (int i = 1; i <= totp; i++)
    if (i == 1 || p[i] != p[newp]) p[++newp] = p[i];
  totp = newp;
  long long basis = 0, bestval = 0;
  for (int i = 1; i <= totp; i++) fa[p[i]] = p[i];
  for (int i = 1; i <= tote; i++) {
    if (find(ma[pe[i]]) == find(mb[pe[i]])) {
      printf("NO\n");
      return;
    }
    merge(ma[pe[i]], mb[pe[i]]);
    basis += mw[pe[i]];
  }
  top = 0;
  totke = 0;
  for (int i = 1; i <= totp; i++) {
    while (top && lca(st[top], p[i]) != st[top]) top--;
    st[++top] = p[i];
    if (top > 1) {
      long long sum, mx;
      sum = dis[st[top]] - dis[st[top - 1]];
      mx = findmx(st[top], st[top - 1]);
      bestval += sum;
      basis += sum - mx;
      if (find(st[top]) != find(st[top - 1])) {
        me[++totke].a = st[top];
        me[totke].b = st[top - 1];
        me[totke].w = mx;
      }
    }
  }
  if (kruskal(basis, 0) == bestval)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%lld", &ma[i], &mb[i], &mw[i]);
    me[i].a = ma[i], me[i].b = mb[i], me[i].w = mw[i];
  }
  totp = n;
  totke = m;
  for (int i = 1; i <= totp; i++) fa[i] = i;
  kruskal(0, 1);
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) {
      pre[j][i] = pre[pre[j][i - 1]][i - 1];
      mx[j][i] = max(mx[j][i - 1], mx[pre[j][i - 1]][i - 1]);
    }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &tote);
    totp = 0;
    for (int i = 1; i <= tote; i++) {
      scanf("%d", &pe[i]);
      p[++totp] = ma[pe[i]], p[++totp] = mb[pe[i]];
    }
    solve();
  }
  return 0;
}
