#include <bits/stdc++.h>
using namespace std;
int Read() {
  int x = 0, flag = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * flag;
}
void Write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) Write(x / 10);
  putchar(x % 10 + 48);
}
struct spNode {
  int fa, ch[2];
  bool rev;
} sp[200005];
bool isrt(int x) { return sp[sp[x].fa].ch[0] != x && sp[sp[x].fa].ch[1] != x; }
bool iden(int x) { return sp[sp[x].fa].ch[1] == x; }
void con(int x, int son, int f) {
  sp[son].fa = x;
  sp[x].ch[f] = son;
}
void rotate(int x) {
  int fa = sp[x].fa, fx = iden(x);
  int grand = sp[fa].fa, ffa = iden(fa);
  bool flag = isrt(fa);
  con(fa, sp[x].ch[fx ^ 1], fx);
  con(x, fa, fx ^ 1);
  if (flag)
    sp[x].fa = grand;
  else
    con(grand, x, ffa);
}
void pushdown(int x) {
  int &lc = sp[x].ch[0], &rc = sp[x].ch[1];
  if (sp[x].rev) {
    swap(lc, rc);
    sp[lc].rev ^= 1;
    sp[rc].rev ^= 1;
    sp[x].rev = 0;
  }
}
void pushall(int x) {
  if (!isrt(x)) pushall(sp[x].fa);
  pushdown(x);
}
void splay(int x) {
  if (!x) return;
  pushall(x);
  while (!isrt(x)) {
    int fx = sp[x].fa;
    if (isrt(fx))
      rotate(x);
    else if (iden(x) ^ iden(fx))
      rotate(x), rotate(x);
    else
      rotate(fx), rotate(x);
  }
}
void access(int x) {
  for (int y = 0; x; y = x, x = sp[x].fa) splay(x), sp[x].ch[1] = y;
}
int findrt(int x) {
  access(x);
  splay(x);
  pushdown(x);
  while (sp[x].ch[0]) pushdown(x = sp[x].ch[0]);
  splay(x);
  return x;
}
void makert(int x) {
  access(x);
  splay(x);
  sp[x].rev ^= 1;
}
void lk(int x, int y) {
  makert(x);
  sp[x].fa = y;
}
void ct(int x, int y) {
  makert(x);
  access(y);
  splay(y);
  sp[x].fa = sp[y].ch[0] = 0;
}
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
int a[1005][1005];
struct coNode {
  int x, y;
  coNode(int xx = 0, int yy = 0) {
    x = xx;
    y = yy;
  }
} co[1005 * 1005];
bool on[1005][1005];
struct SegNode {
  int mn, tag, tot;
  SegNode(int a = 0, int b = 0, int c = 1) {
    mn = a;
    tag = b;
    tot = c;
  }
  friend SegNode operator+(SegNode X, SegNode Y) {
    return SegNode(min(X.mn, Y.mn), 0,
                   (X.mn <= Y.mn) * X.tot + (X.mn >= Y.mn) * Y.tot);
  }
} Seg[200005 << 2];
void pushdown(int p, int l, int r) {
  int &t = Seg[p].tag;
  if (t) {
    Seg[p << 1].mn += t;
    Seg[p << 1].tag += t;
    Seg[p << 1 | 1].mn += t;
    Seg[p << 1 | 1].tag += t;
    t = 0;
  }
}
void build(int l, int r, int p) {
  Seg[p].tot = r - l + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, p << 1);
  build(mid + 1, r, p << 1 | 1);
}
void update(int l, int r, int p, int Aiml, int Aimr, int x) {
  if (Aiml <= l && r <= Aimr) {
    Seg[p].mn += x;
    Seg[p].tag += x;
    return;
  }
  pushdown(p, l, r);
  int mid = (l + r) >> 1;
  if (Aiml <= mid) update(l, mid, p << 1, Aiml, Aimr, x);
  if (Aimr > mid) update(mid + 1, r, p << 1 | 1, Aiml, Aimr, x);
  int tmp = Seg[p].tag;
  Seg[p] = Seg[p << 1] + Seg[p << 1 | 1];
  Seg[p].tag = tmp;
}
int query(int l, int r, int p, int Aiml, int Aimr) {
  if (Aiml <= l && r <= Aimr) return (Seg[p].mn == 1) * Seg[p].tot;
  pushdown(p, l, r);
  int mid = (l + r) >> 1;
  int tans = 0;
  if (Aiml <= mid) tans += query(l, mid, p << 1, Aiml, Aimr);
  if (Aimr > mid) tans += query(mid + 1, r, p << 1 | 1, Aiml, Aimr);
  return tans;
}
bool check(int c) {
  int x = co[c].x, y = co[c].y;
  int f[5], cnt = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (on[xx][yy]) f[++cnt] = findrt((xx - 1) * m + yy);
  }
  for (int i = 1; i <= cnt; i++)
    for (int j = i + 1; j <= cnt; j++)
      if (f[i] == f[j]) return 0;
  return 1;
}
void Lk(int c) {
  int x = co[c].x, y = co[c].y;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (on[xx][yy]) {
      lk((x - 1) * m + y, (xx - 1) * m + yy);
      update(1, n * m, 1, 1, a[xx][yy], -1);
    }
  }
  on[x][y] = 1;
}
void Ct(int c) {
  int x = co[c].x, y = co[c].y;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (on[xx][yy]) ct((x - 1) * m + y, (xx - 1) * m + yy);
  }
  on[x][y] = 0;
}
int main() {
  n = Read(), m = Read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) co[a[i][j] = Read()] = coNode(i, j);
  build(1, n * m, 1);
  int l = 1;
  long long ans = 0;
  for (int i = 1; i <= n * m; i++) {
    for (; l <= i && !check(i); l++) Ct(l);
    update(1, n * m, 1, l, i, 1);
    Lk(i);
    ans += query(1, n * m, 1, l, i);
  }
  Write(ans);
  (putchar('\n'));
  return 0;
}
