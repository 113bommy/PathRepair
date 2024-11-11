#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& num) {
  char CH;
  bool F = false;
  for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
    ;
  for (num = 0; CH >= '0' && CH <= '9';
       num = num * 10 + CH - '0', CH = getchar())
    ;
  F && (num = -num);
}
int stk[70], tp;
template <class T>
inline void print(T p) {
  if (!p) {
    puts("0");
    return;
  }
  tp = 0;
  while (p) stk[++tp] = p % 10, p /= 10;
  while (tp) putchar(stk[tp--] + '0');
  putchar('\n');
}
const int maxn = 200005, maxm = 400005;
int g[maxn], v[maxm], nxt[maxm], eid;
int siz[maxn], son[maxn], top[maxn], f[maxn];
int st[maxn], ed[maxn], vid;
int n, m, x;
char op[10];
void add(int a, int b) {
  v[eid] = b;
  nxt[eid] = g[a];
  g[a] = eid++;
}
struct Segtree {
  int sumv[maxm], sam[maxm], l[maxm], r[maxm];
  void update(int x) { sumv[x] = sumv[((x) << 1)] + sumv[(((x) << 1) | 1)]; }
  void push(int x) {
    if (sam[x] == -1) return;
    sam[((x) << 1)] = sam[x];
    sumv[((x) << 1)] = sam[x] * (r[((x) << 1)] - l[((x) << 1)] + 1);
    sam[(((x) << 1) | 1)] = sam[x];
    sumv[(((x) << 1) | 1)] =
        sam[x] * (r[(((x) << 1) | 1)] - l[(((x) << 1) | 1)] + 1);
    sam[x] = -1;
  }
  void change(int x, int L, int R, int val) {
    if (R < l[x] || L > r[x]) return;
    if (L <= l[x] && r[x] <= R) {
      sam[x] = val;
      sumv[x] = (r[x] - l[x] + 1) * val;
      return;
    }
    push(x);
    change(((x) << 1), L, R, val);
    change((((x) << 1) | 1), L, R, val);
    update(x);
  }
  int query(int x, int L, int R) {
    if (R < l[x] || L > r[x]) return 0;
    if (L <= l[x] && r[x] <= R) return sumv[x];
    push(x);
    return (query(((x) << 1), L, R) + query((((x) << 1) | 1), L, R));
  }
  void build(int x, int L, int R) {
    l[x] = L;
    r[x] = R;
    sam[x] = -1;
    if (L == R) return;
    int mid = L + R >> 1;
    build(((x) << 1), L, mid);
    build((((x) << 1) | 1), mid + 1, R);
  }
} seg;
void dfs(int u) {
  siz[u] = 1;
  for (int i = g[u]; ~i; i = nxt[i]) {
    dfs(v[i]);
    siz[u] += siz[v[i]];
    if (siz[v[i]] > siz[son[u]]) son[u] = v[i];
  }
}
void dfs2(int u, int rt) {
  top[u] = rt;
  st[u] = ++vid;
  if (son[u]) dfs2(son[u], rt);
  for (int i = g[u]; ~i; i = nxt[i])
    if (v[i] != son[u]) dfs2(v[i], v[i]);
  ed[u] = vid;
}
void solve(int x) {
  int ans = 0;
  while (x) {
    ans += (st[x] - st[top[x]] + 1) - seg.query(1, st[top[x]], st[x]);
    seg.change(1, st[top[x]], st[x], 1);
    x = top[x];
    x = f[x];
  }
  print(ans);
}
int fa[100005][40], w[100005], gmin[100005][40];
long long gsum[100005][40], k;
int main() {
  read(n);
  read(k);
  for (int i = 0; i < n; ++i) read(fa[i][0]);
  for (int i = 0; i < n; ++i) read(w[i]), gsum[i][0] = gmin[i][0] = w[i];
  for (int j = 1; j < 40; ++j)
    for (int i = 0; i < n; ++i) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
      gsum[i][j] = gsum[i][j - 1] + gsum[fa[i][j - 1]][j - 1];
      gmin[i][j] = min(gmin[i][j - 1], gmin[fa[i][j - 1]][j - 1]);
    }
  for (int i = 0; i < n; ++i) {
    int x = i, mn = 0x7fffffff;
    long long sum = 0;
    for (int j = 39; ~j; --j)
      if (k & (1LL << j)) {
        sum += gsum[x][j];
        mn = min(mn, gmin[x][j]);
        x = fa[x][j];
      }
    print(sum);
    print(mn);
  }
  return 0;
}
