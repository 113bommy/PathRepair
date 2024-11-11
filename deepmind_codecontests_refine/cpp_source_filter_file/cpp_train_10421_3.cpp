#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 100;
const long double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
inline long long readll() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
int pos[N << 1], tot = 1, lst = 1, ch[N << 1][26], tax[N << 1], fa[N << 1],
                 ord[N << 1], len[N << 1];
void insert(int x, int id) {
  int np = (++tot), p = lst;
  pos[np] = id;
  len[np] = len[p] + 1;
  lst = np;
  while ((p) && (!ch[p][x])) {
    ch[p][x] = np;
    p = fa[p];
  }
  if (!p) {
    fa[np] = 1;
    return;
  }
  int q = ch[p][x];
  if (len[q] == len[p] + 1) {
    fa[np] = q;
    return;
  }
  int nq = (++tot);
  len[nq] = len[p] + 1;
  memcpy(ch[nq], ch[q], sizeof(ch[nq]));
  fa[nq] = fa[q];
  fa[np] = fa[q] = nq;
  while ((p) && (ch[p][x] == q)) {
    ch[p][x] = nq;
    p = fa[p];
  }
}
int tot1 = 0, rt[N << 1], lson[N * 100], rson[N * 100];
void modify(int &id, int l, int r, int pos) {
  id = (++tot1);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (pos <= mid)
    modify(lson[id], l, mid, pos);
  else
    modify(rson[id], mid + 1, r, pos);
}
int merge(int x, int y, int l, int r) {
  if ((!x) || (!y)) return x + y;
  int id = (++tot1), mid = (l + r) >> 1;
  lson[id] = merge(lson[x], lson[y], l, mid);
  rson[id] = merge(rson[x], rson[y], mid + 1, r);
  return id;
}
int query(int id, int l, int r, int ql, int qr) {
  if (!id) return 0;
  if ((l >= ql) && (r <= qr)) return 1;
  int mid = (l + r) >> 1;
  if ((ql <= mid) && (query(lson[id], l, mid, ql, qr))) return 1;
  if ((qr > mid) && (query(rson[id], mid + 1, r, ql, qr))) return 1;
  return 0;
}
int n, q;
char s[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (register int i = 1; i <= n; i++) insert(s[i] - 'a', i);
  for (register int i = 1; i <= tot; i++) tax[len[i]]++;
  for (register int i = 1; i <= n; i++) tax[i] += tax[i - 1];
  for (register int i = 1; i <= tot; i++) ord[tax[len[i]]--] = i;
  for (register int i = 1; i <= tot; i++)
    if (pos[i]) modify(rt[i], 1, n, pos[i]);
  for (register int i = 1; i <= tot; i++) {
    int u = ord[i];
    if (fa[u]) rt[fa[u]] = merge(rt[fa[u]], rt[u], 1, n);
  }
  q = read();
  while (q--) {
    int l = read(), r = read();
    scanf("%s", s + 1);
    int m = strlen(s + 1), len = -1, c = -1, now = 1;
    s[m + 1] = ' ';
    for (register int i = 1; i <= m + 1; i++) {
      if (l + i - 1 > r) break;
      for (register int j = max(s[i] - 'a' + 1, 0); j <= 25; j++) {
        int nxt = ch[now][j];
        if (!nxt) continue;
        if (query(rt[nxt], 1, n, l + i - 1, r)) {
          if (len == -1) {
            len = i - 1;
            c = j;
          } else if ((len != i - 1) && (s[len + 1] - 'a' < c)) {
            len = i - 1;
            c = j;
          }
        }
      }
      if (i <= m) now = ch[now][s[i] - 'a'];
      if (!now) break;
    }
    if (len == -1)
      puts("-1");
    else {
      for (register int i = 1; i <= len; i++) putchar(s[i]);
      putchar('a' + c);
      puts("");
    }
  }
  return 0;
}
