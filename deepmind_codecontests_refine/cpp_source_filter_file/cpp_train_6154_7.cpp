#include <bits/stdc++.h>
using namespace std;
int i, n, a[200005], b[200005], ch[200005][2], root[400005], fa[200005],
    siz[200005], w[200005], f[400005], s[400005], l[400005], r[400005], k;
long long ans, sum[200005], sb[200005], sizb[200005];
void pushup(int i) {
  siz[i] = siz[ch[i][0]] + siz[ch[i][1]] + 1;
  sizb[i] = sizb[ch[i][0]] + sizb[ch[i][1]] + w[i];
  sum[i] = sum[ch[i][0]] + sum[ch[i][1]] +
           sizb[ch[i][1]] * (siz[ch[i][0]] + 1) + 1ll * w[i] * siz[ch[i][0]];
}
void rotate(int x) {
  int y = fa[x];
  bool d = (ch[y][0] == x);
  ch[y][!d] = ch[x][d];
  if (ch[x][d] != 0) fa[ch[x][d]] = y;
  fa[x] = fa[y];
  if (fa[y] != 0) ch[fa[y]][ch[fa[y]][1] == y] = x;
  ch[x][d] = y;
  fa[y] = x;
  pushup(y);
  pushup(x);
}
void splay(int i, int x) {
  for (int y = fa[x]; y != 0; rotate(x), y = fa[x])
    if (fa[y] && (ch[fa[y]][0] == y) == (ch[y][0] == x)) rotate(y);
  root[i] = x;
}
void Insert(int pos, int i, int x) {
  if (w[i] < w[x]) {
    if (ch[i][0] == 0) {
      ch[i][0] = x;
      fa[x] = i;
      splay(pos, x);
      return;
    }
    Insert(pos, ch[i][0], x);
  } else {
    if (ch[i][1] == 0) {
      ch[i][1] = x;
      fa[x] = i;
      splay(pos, x);
      return;
    }
    Insert(pos, ch[i][1], x);
  }
}
void copy(int i, int b) {
  if (i == 0) return;
  int lc = ch[i][0], rc = ch[i][1];
  copy(lc, b);
  ch[i][0] = ch[i][1] = fa[i] = 0;
  Insert(b, root[b], i);
  copy(rc, b);
}
int Find(int x) {
  if (f[x] == 0) return x;
  return f[x] = Find(f[x]);
}
void uniot(int x, int y) {
  int a = Find(x), b = Find(y);
  if (a != b) {
    if (s[a] > s[b]) swap(a, b);
    ans -= sum[root[a]] + sb[a] * l[a];
    ans -= sum[root[b]] + sb[b] * l[b];
    copy(root[a], b);
    ans += sum[root[b]];
    f[a] = b;
    s[b] += s[a];
    l[b] = min(l[b], l[a]);
    r[b] = max(r[b], r[a]);
    sb[b] += sb[a];
    ans += sb[b] * l[b];
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    ans -= 1ll * a[i] * b[i];
    int pos = a[i];
    if (l[Find(a[i])] != 0) pos = r[Find(a[i])] + 1;
    w[++k] = b[i];
    l[pos] = r[pos] = pos;
    sb[pos] = b[i];
    s[pos] = 1;
    ans += 1ll * b[i] * pos;
    pushup(k);
    root[pos] = k;
    if (l[Find(pos - 1)] != 0) uniot(pos - 1, pos);
    if (l[Find(pos + 1)] != 0) uniot(pos + 1, pos);
    printf("%lld\n", ans);
  }
}
