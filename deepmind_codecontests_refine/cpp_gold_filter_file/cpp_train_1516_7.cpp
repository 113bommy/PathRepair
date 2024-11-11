#include <bits/stdc++.h>
using namespace std;
const int NR = 5e5 + 10;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, rt;
struct Mashiro {
  int c, q;
  bool operator<(const Mashiro& A) const {
    if (q == A.q) return c < A.c;
    return q > A.q;
  }
} t[NR];
struct Kirino {
  int id, x, cnt;
} num[NR];
Kirino md(int id, int x, int cnt) {
  Kirino tmp;
  tmp.id = id, tmp.x = x, tmp.cnt = cnt;
  return tmp;
}
int tt;
int ans[NR];
struct Fhqtreap {
  int val[NR], id[NR], cnt[NR], key[NR], siz[NR], son[NR][2], lz1[NR], lz2[NR],
      tot;
  int bin[NR], top;
  void update(int rt) { siz[rt] = siz[son[rt][0]] + siz[son[rt][1]]; }
  int newnode(int num, int x, int cn) {
    int now = top ? bin[top--] : ++tot;
    id[now] = num, val[now] = x, cnt[now] = cn;
    key[now] = rand(), siz[now] = 1;
    son[now][0] = son[now][1] = 0;
    lz1[now] = lz2[now] = 0;
    return now;
  }
  void push_down(int rt) {
    if (lz1[rt]) {
      if (son[rt][0]) val[son[rt][0]] -= lz1[rt], lz1[son[rt][0]] += lz1[rt];
      if (son[rt][1]) val[son[rt][1]] -= lz1[rt], lz1[son[rt][1]] += lz1[rt];
      lz1[rt] = 0;
    }
    if (lz2[rt]) {
      if (son[rt][0]) cnt[son[rt][0]] += lz2[rt], lz2[son[rt][0]] += lz2[rt];
      if (son[rt][1]) cnt[son[rt][1]] += lz2[rt], lz2[son[rt][1]] += lz2[rt];
      lz2[rt] = 0;
    }
  }
  void split(int rt, int k, int& x, int& y) {
    if (!rt) {
      x = y = 0;
      return;
    }
    push_down(rt);
    if (val[rt] <= k)
      x = rt, split(son[rt][1], k, son[rt][1], y);
    else
      y = rt, split(son[rt][0], k, x, son[rt][0]);
    update(rt);
  }
  int merge(int x, int y) {
    if (!x || !y) return x | y;
    push_down(x), push_down(y);
    if (key[x] > key[y]) {
      son[x][1] = merge(son[x][1], y);
      update(x);
      return x;
    } else {
      son[y][0] = merge(x, son[y][0]);
      update(y);
      return y;
    }
  }
  void ins(int num, int x, int cnt) {
    int p, q;
    split(rt, x, p, q);
    rt = merge(p, merge(newnode(num, x, cnt), q));
  }
  void rein(int rt, int p) {
    push_down(rt);
    bin[++top] = rt, num[++tt] = md(id[rt], val[rt] - p, cnt[rt] + 1);
    if (son[rt][0]) rein(son[rt][0], p);
    if (son[rt][1]) rein(son[rt][1], p);
  }
  void add(int rt, int p) {
    if (!rt) return;
    val[rt] -= p, lz1[rt] += p;
    cnt[rt]++, lz2[rt]++;
  }
  void dfs(int rt) {
    push_down(rt);
    ans[id[rt]] = cnt[rt];
    if (son[rt][0]) dfs(son[rt][0]);
    if (son[rt][1]) dfs(son[rt][1]);
  }
} T;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) t[i].c = read(), t[i].q = read();
  sort(t + 1, t + n + 1);
  m = read();
  for (int i = 1, x; i <= m; i++) x = read(), T.ins(i, x, 0);
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    T.split(rt, t[i].c - 1, x, y), T.split(y, t[i].c * 2 - 1, y, z);
    T.add(z, t[i].c), rt = T.merge(x, z);
    if (y) T.rein(y, t[i].c);
    for (int j = 1; j <= tt; j++) T.ins(num[j].id, num[j].x, num[j].cnt);
    tt = 0;
  }
  T.dfs(rt);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
