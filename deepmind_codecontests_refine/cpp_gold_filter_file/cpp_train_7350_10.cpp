#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int x[1010], y[1010];
struct Lin {
  int l, r, y;
  int v;
  Lin(int _l = 0, int _r = 0, int _y = 0, int _v = 0)
      : l(_l), r(_r), y(_y), v(_v) {}
  bool operator<(const Lin& lx) const { return y < lx.y; }
  void out() { printf("l=%d,r=%d,y=%d,v=%d\n", l, r, y, v); }
} lin[1010];
int mn[1010 << 2], add[1010 << 2];
void deal(int o, int val) {
  add[o] += val;
  mn[o] += val;
}
void down(int o) {
  deal((o << 1), add[o]);
  deal(((o << 1) | 1), add[o]);
  add[o] = 0;
}
void up(int o) { mn[o] = min(mn[(o << 1)], mn[((o << 1) | 1)]); }
void build(int o, int l, int r) {
  mn[o] = 0;
  add[o] = 0;
  if (l != r) {
    build((o << 1), l, ((l + r) >> 1));
    build(((o << 1) | 1), ((l + r) >> 1) + 1, r);
  }
}
void update(int o, int l, int r, int y1, int y2, int val) {
  if (y1 <= l && y2 >= r) {
    deal(o, val);
    return;
  }
  down(o);
  if (y1 <= ((l + r) >> 1)) update((o << 1), l, ((l + r) >> 1), y1, y2, val);
  if (y2 > ((l + r) >> 1))
    update(((o << 1) | 1), ((l + r) >> 1) + 1, r, y1, y2, val);
  up(o);
}
int t[1010], sz;
int MAX[2], MIN[2];
bool judge(int len) {
  memset(MAX, -1, sizeof(MAX));
  memset(MIN, -1, sizeof(MIN));
  bool ok = true;
  for (int _ = 0; _ < 2; ++_) {
    sz = 0;
    int tot = 0;
    t[sz++] = 1;
    t[sz++] = n + 1;
    for (int i = 0; i < k; ++i) {
      int l = max(1, x[i] - len), r = min(n + 1, x[i] + len + 1);
      int yx = max(1, y[i] - len);
      lin[tot++] = Lin(l, r, yx, 1);
      t[sz++] = l;
      t[sz++] = r;
      if (y[i] + len < m) lin[tot++] = Lin(l, r, y[i] + len + 1, -1);
    }
    sort(t, t + sz);
    sz = unique(t, t + sz) - t;
    for (int i = 0; i < tot; ++i) {
      lin[i].l = lower_bound(t, t + sz, lin[i].l) - t + 1;
      lin[i].r = lower_bound(t, t + sz, lin[i].r) - t;
    }
    sz--;
    build(1, 1, sz);
    lin[tot++] = Lin(1, sz, 1, 0);
    lin[tot++] = Lin(1, sz, m, 0);
    sort(lin, lin + tot);
    int now = 0;
    bool fk = true;
    while (now < tot) {
      int las = now;
      while (now < tot && lin[now].y == lin[las].y) {
        update(1, 1, sz, lin[now].l, lin[now].r, lin[now].v);
        now++;
      }
      if (!fk) {
        if (MAX[_] == -1 || MAX[_] < lin[las].y - 1) MAX[_] = lin[las].y - 1;
        if (MIN[_] == -1 || MIN[_] > lin[las].y - 1) MIN[_] = lin[las].y - 1;
      }
      if (mn[1] < 1) {
        if (MAX[_] == -1 || MAX[_] < lin[las].y) MAX[_] = lin[las].y;
        if (MIN[_] == -1 || MIN[_] > lin[las].y) MIN[_] = lin[las].y;
        fk = false;
      } else
        fk = true;
    }
    if (MAX[_] != -1 && MAX[_] - MIN[_] > len * 2) {
      ok = false;
    }
    for (int i = 0; i < k; ++i) swap(x[i], y[i]);
    swap(n, m);
  }
  return ok;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) scanf("%d%d", &x[i], &y[i]);
  long long lb = 0, ub = max(n, m) + 1;
  if (k + 1 == n * m) {
    puts("0");
    exit(0);
  }
  while (ub > lb + 1) {
    long long md = (lb + ub) >> 1;
    if (judge(md))
      ub = md;
    else
      lb = md;
  }
  printf("%I64d\n", ub);
  return 0;
}
