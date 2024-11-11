#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  return sum * t;
}
struct node {
  int nxt[26], par, len, rt;
} c[400005];
int tot = 1, rt = 1, las = 1;
void insert(int x) {
  int np = ++tot, p = las, q, nq;
  c[np].len = c[p].len + 1;
  for (; p && !c[p].nxt[x]; p = c[p].par) c[p].nxt[x] = np;
  if (!p)
    c[np].par = rt;
  else {
    q = c[p].nxt[x];
    if (c[q].len == c[p].len + 1)
      c[np].par = q;
    else {
      c[nq = ++tot] = c[q];
      c[nq].len = c[p].len + 1;
      c[q].par = c[np].par = nq;
      for (; p && c[p].nxt[x] == q; p = c[p].par) c[p].nxt[x] = nq;
    }
  }
  las = np;
}
int nxt[400005], to[400005], fir[400005], cnt;
int fa[400005][19], dep[400005];
void add(int x, int y) {
  nxt[++cnt] = fir[x];
  to[cnt] = y;
  fir[x] = cnt;
}
void dfs(int x) {
  for (int i = 1; i < 19; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = fir[x]; i; i = nxt[i]) {
    int y = to[i];
    dep[y] = dep[x] + 1;
    fa[y][0] = x;
    dfs(y);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int d = dep[x] - dep[y];
  for (int i = 0; i < 19; i++)
    if (d >> i & 1) x = fa[x][i];
  if (x == y) return x;
  for (int i = 18; ~i; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
char s[400005], t[400005];
int who[400005];
int L1, L2;
bool cmp(int x, int y) {
  bool flag = false;
  if (x > y) swap(x, y), flag = true;
  if (x + L2 <= y) {
    int L = who[L1 + 1], R = who[x + 1];
    int lcp = c[lca(L, R)].len;
    if (lcp >= L2) {
      L = R, R = who[x + L2 + 1];
      lcp = c[lca(L, R)].len;
      if (x + L2 + lcp < y)
        return (s[x + lcp + 1] < s[x + L2 + lcp + 1]) ^ flag;
      else {
        L = who[y + 1 - L2], R = who[L1 + 1];
        lcp = c[lca(L, R)].len;
        if (lcp >= L2)
          return !flag;
        else
          return (s[y + 1 - L2 + lcp] < t[lcp + 1]) ^ flag;
      }
    } else
      return (t[lcp + 1] < s[x + lcp + 1]) ^ flag;
  } else {
    int L = who[L1 + 1], R = who[x + 1];
    int lcp = c[lca(L, R)].len;
    if (lcp >= y - x) {
      R = L, L = who[L1 + y - x + 1];
      lcp = c[lca(L, R)].len;
      if (lcp + y - x >= L2) {
        L = who[x + 1], R = who[x + L2 - y + L1 + 1];
        lcp = c[lca(L, R)].len;
        if (lcp >= y - x)
          return !flag;
        else
          return (s[x + lcp + 1] < t[x + L2 - y + lcp + 1]) ^ flag;
      } else
        return (t[y - x + lcp + 1] < t[lcp + 1]) ^ flag;
    } else
      return (t[lcp + 1] < s[x + lcp + 1]) ^ flag;
  }
}
struct Node {
  int ins;
  bool operator<(const Node &a) const { return cmp(ins, a.ins); }
} rk[400005];
int a[400005], q;
int head[400005], nex[400005];
struct Query {
  int ans, l, r, x, y;
} qry[400005];
int f[19][400005], Log[400005], g[19][400005];
void build(int st[][400005], int len) {
  for (int i = 1; i <= 17; i++)
    for (int j = 0; j <= len && j + (1 << i) <= len + 1; j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int query(int st[][400005], int l, int r) {
  int len = Log[r - l + 1];
  return min(st[len][l], st[len][r - (1 << len) + 1]);
}
int main() {
  scanf("%s", s + 1);
  L1 = strlen(s + 1);
  scanf("%s", t + 1);
  L2 = strlen(t + 1);
  for (int i = L2; i; i--) insert(t[i] - 'a'), who[c[las].rt = i + L1] = las;
  for (int i = L1; i; i--) insert(s[i] - 'a'), who[c[las].rt = i] = las;
  for (int i = 1; i <= tot; i++)
    if (c[i].par) add(c[i].par, i);
  dfs(1);
  for (int i = 0; i <= L1; i++) rk[i].ins = i;
  sort(rk, rk + L1 + 1);
  for (int i = 0; i <= L1; i++) a[rk[i].ins] = i;
  for (int i = 2; i <= L1; i++) Log[i] = Log[i >> 1] + 1;
  for (int i = 0; i <= L1; i++) f[0][i] = a[i];
  build(f, L1);
  q = read();
  for (int i = 1; i <= q; i++) {
    qry[i].l = read();
    qry[i].r = read();
    int k = read();
    qry[i].x = read();
    qry[i].y = read();
    qry[i].ans = L1 + 1;
    nex[i] = head[k];
    head[k] = i;
  }
  for (int i = 1; i <= L1; i++)
    if (head[i]) {
      if (i <= 80) {
        for (int k, j = 0; j < i; j++) {
          for (k = 0; k * i + j <= L1; k++) g[0][k] = f[0][k * i + j];
          build(g, k - 1);
          for (k = head[i]; k; k = nex[k])
            if (qry[k].x <= j && qry[k].y >= j) {
              int x = (qry[k].l - j) / i;
              if (x * i + j < qry[k].l) x++;
              int y = (qry[k].r - j) / i;
              if (x * i + j > qry[k].r) y--;
              if (x <= y) qry[k].ans = min(qry[k].ans, query(g, x, y));
            }
        }
      } else {
        for (int j = head[i]; j; j = nex[j])
          for (int k = 0; k * i <= L1; k++) {
            int x = max(k * i + qry[j].x, qry[j].l),
                y = min(k * i + qry[j].y, qry[j].r);
            if (x <= y) qry[k].ans = min(qry[k].ans, query(f, x, y));
          }
      }
    }
  rk[L1 + 1].ins = -1;
  for (int i = 1; i <= q; i++)
    printf("%d%c", rk[qry[i].ans].ins, (i < q) ? ' ' : '\n');
}
