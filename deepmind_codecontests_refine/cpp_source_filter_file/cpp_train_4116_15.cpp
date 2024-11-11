#include <bits/stdc++.h>
using namespace std;
const int N = 15e4 + 5;
const int K = 31;
int n, m, p, a[N], opt, tmp1, tmp2, tmp3, lim;
int q[N], g[N];
int tag[N << 2];
struct node {
  int k, mj[K], cnt[K];
} t[N << 3], Ans;
struct data {
  int mj, cnt;
} tmp[K << 3];
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return f * x;
}
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
bool cmp(const data x, const data y) {
  if (x.cnt == y.cnt) return x.mj > y.mj;
  return x.cnt > y.cnt;
}
node Pushup(node lson, node rson) {
  node ret;
  ret = lson;
  for (register int i = (1); i <= (rson.k); i++) {
    int flag = 0;
    for (register int j = (1); j <= (ret.k); j++)
      if (ret.mj[j] == rson.mj[i]) {
        flag = 1;
        ret.cnt[j] += rson.cnt[i];
        break;
      }
    if (flag) continue;
    if (ret.k < lim) {
      ret.k++;
      ret.mj[ret.k] = rson.mj[i];
      ret.cnt[ret.k] = rson.cnt[i];
      continue;
    }
    int mn = 1;
    for (register int j = (1); j <= (ret.k); j++)
      if (ret.cnt[j] < ret.cnt[mn]) mn = j;
    if (ret.mj[mn] > rson.mj[i]) {
      for (register int j = (1); j <= (ret.k); j++) ret.cnt[j] -= rson.cnt[i];
      continue;
    } else {
      int bi = ret.cnt[mn];
      ret.mj[mn] = rson.mj[i];
      ret.cnt[mn] = rson.cnt[i];
      for (register int j = (1); j <= (ret.k); j++) ret.cnt[j] -= bi;
      continue;
    }
  }
  return ret;
}
void Build(int p, int l, int r) {
  if (l == r) {
    t[p].k = 1;
    t[p].mj[1] = a[l];
    t[p].cnt[1] = 1;
    return;
  }
  int ls = p << 1, rs = p << 1 | 1, mid = (l + r) >> 1;
  Build(ls, l, mid);
  Build(rs, mid + 1, r);
  t[p] = Pushup(t[ls], t[rs]);
  return;
}
void DO(int p, int l, int r, int val) {
  if (!p) return;
  t[p].k = 1;
  t[p].mj[1] = val;
  t[p].cnt[1] = r - l + 1;
  tag[p] = val;
  return;
}
void Pushdown(int p, int l, int r) {
  if (!tag[p]) return;
  int ls = p << 1, rs = p << 1 | 1, mid = (l + r) >> 1;
  DO(ls, l, mid, tag[p]);
  DO(rs, mid + 1, r, tag[p]);
  tag[p] = 0;
  return;
}
void Modify(int p, int l, int r, int L, int R, int val) {
  if (L <= l && r <= R) {
    t[p].k = 1;
    t[p].mj[1] = val;
    t[p].cnt[1] = r - l + 1;
    tag[p] = val;
    return;
  }
  int ls = p << 1, rs = p << 1 | 1, mid = (l + r) >> 1;
  Pushdown(p, l, r);
  if (L <= mid) Modify(ls, l, mid, L, R, val);
  if (R > mid) Modify(rs, mid + 1, r, L, R, val);
  t[p] = Pushup(t[ls], t[rs]);
  return;
}
node Query(int p, int l, int r, int L, int R) {
  if (L <= l && r <= R) return t[p];
  node ret;
  ret.k = 0;
  int ls = p << 1, rs = p << 1 | 1, mid = (l + r) >> 1;
  Pushdown(p, l, r);
  if (L <= mid) ret = Pushup(ret, Query(ls, l, mid, L, R));
  if (R > mid) ret = Pushup(ret, Query(rs, mid + 1, r, L, R));
  t[p] = Pushup(t[ls], t[rs]);
  return ret;
}
int main() {
  n = read(), m = read(), p = read();
  lim = 100 / p;
  for (register int i = (1); i <= (n); i++) a[i] = read();
  Build(1, 1, n);
  while (m--) {
    opt = read(), tmp1 = read(), tmp2 = read();
    switch (opt) {
      case 1:
        tmp3 = read();
        Modify(1, 1, n, tmp1, tmp2, tmp3);
        break;
      case 2:
        Ans = Query(1, 1, n, tmp1, tmp2);
        write(Ans.k);
        for (register int i = (1); i <= (Ans.k); i++)
          putchar(' '), write(Ans.mj[i]);
        putchar('\n');
        break;
    }
  }
  return 0;
}
