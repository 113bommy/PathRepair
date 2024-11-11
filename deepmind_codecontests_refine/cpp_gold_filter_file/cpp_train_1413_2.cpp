#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long next, to;
  long long w;
} e[500100 * 2];
long long head[500100], bian;
void add(long long x, long long y, long long w) {
  bian++;
  e[bian].next = head[x], head[x] = bian;
  e[bian].to = y, e[bian].w = w;
}
long long siz[500100], son[500100], f[1 << 22], st[500100], de[500100];
void dfs1(long long x, long long pre, long long dep) {
  long long ma = 0;
  siz[x] = 1, son[x] = -1, de[x] = dep;
  for (long long i = head[x]; i != -1; i = e[i].next) {
    long long y = e[i].to;
    if (y == pre) continue;
    st[y] = st[x] ^ e[i].w;
    dfs1(y, x, dep + 1);
    siz[x] += siz[y];
    if (siz[y] > ma) ma = siz[y], son[x] = y;
  }
}
long long fal;
long long ans[500100];
long long solve(long long x, long long root) {
  long long ma = 0;
  if (f[st[x]] >= 1) ma = f[st[x]] + de[x] - 2 * de[root];
  for (long long i = 0; i <= 21; i++) {
    long long t = st[x] ^ (1 << i);
    if (f[t] >= 1) {
      ma = max(ma, f[st[x] ^ (1 << i)] + de[x] - 2 * de[root]);
    }
  }
  return ma;
}
long long mas;
void dfs3(long long x, long long pre, long long root) {
  mas = max(mas, solve(x, root));
  for (long long i = head[x]; i != -1; i = e[i].next) {
    long long y = e[i].to;
    if (y == pre) continue;
    dfs3(y, x, root);
  }
}
void dfs4(long long x, long long pre, long long dep) {
  f[st[x]] = max(f[st[x]], dep);
  for (long long i = head[x]; i != -1; i = e[i].next) {
    long long y = e[i].to;
    if (y == pre) continue;
    dfs4(y, x, dep + 1);
  }
}
void coun(long long x, long long pre) {
  f[st[x]] = 0;
  for (long long i = head[x]; i != -1; i = e[i].next) {
    long long y = e[i].to;
    if (y == pre) continue;
    coun(y, x);
  }
}
void dfs2(long long x, long long pre, long long dep, long long q) {
  ans[x] = 0;
  for (long long i = head[x]; i != -1; i = e[i].next) {
    long long y = e[i].to;
    if (y == pre || y == son[x]) continue;
    dfs2(y, x, dep + 1, 0);
    ans[x] = max(ans[x], ans[y]);
  }
  if (son[x] != -1)
    dfs2(son[x], x, dep + 1, 1), ans[x] = max(ans[x], ans[son[x]]);
  for (int i = head[x]; i != -1; i = e[i].next) {
    int y = e[i].to;
    if (y == pre || y == son[x]) continue;
    mas = 0;
    dfs3(y, x, x);
    ans[x] = max(ans[x], mas);
    dfs4(y, x, dep + 1);
  }
  ans[x] = max(ans[x], solve(x, x));
  f[st[x]] = max(f[st[x]], dep);
  if (q == 0) coun(x, pre);
}
int main() {
  long long n;
  scanf("%lld", &n);
  memset(head, -1, sizeof(head)), bian = -1;
  for (long long i = 2; i <= n; i++) {
    long long a;
    char c[2];
    scanf("%lld %s", &a, &c);
    add(a, i, 1 << (c[0] - 'a'));
  }
  st[1] = 0;
  dfs1(1, -1, 0);
  dfs2(1, -1, 0, 0);
  printf("%lld", ans[1]);
  for (long long i = 2; i <= n; i++) printf(" %lld", ans[i]);
  printf("\n");
}
