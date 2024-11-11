#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5;
struct node {
  int idx, x;
} st[MN];
int N, M, tp;
long long b[MN], s[MN];
inline void chkmin(long long &x, long long y) { x = min(x, y); }
inline int sign(long long x) {
  if (x > 0)
    return 1;
  else if (x < 0)
    return -1;
  else
    return 0;
}
inline int check(long long xp, long long yp, long long xq, long long yq) {
  int w1 = sign(xp) * sign(yq), w2 = sign(xq) * sign(yp);
  if (w1 != w2) return w1 > w2;
  if (w1 == 0) return 0;
  return (long double)xp * yq > (long double)xq * yp;
}
inline long long calc(node x, int h) {
  return b[h] - b[x.idx] + 1ll * (x.x - 1) * (s[h] - s[x.idx]);
}
inline void add(int val, int x) {
  if (calc(st[tp], val) == 0) return;
  int y = calc((node){val, x}, val);
  while (tp >= 2) {
    if (check(st[tp].idx - st[tp - 1].idx,
              calc(st[tp], val) - calc(st[tp - 1], val), x - st[tp].x,
              y - calc(st[tp], val)))
      break;
    --tp;
  }
  st[++tp] = (node){val, x};
}
inline void pop(int x) {
  while (tp >= 2 && calc(st[tp], x) >= calc(st[tp - 1], x)) --tp;
}
int main() {
  scanf("%d%d", &N, &M);
  st[tp = 1] = (node){0, 1};
  for (int i = 1, op; i <= M; ++i) {
    long long x, y;
    b[i] = b[i - 1], s[i] = s[i - 1];
    scanf("%d%lld", &op, &x);
    if (op == 1) {
      b[i] = s[i] = 0;
      st[tp = 1] = (node){i, 1};
      N += x;
    } else if (op == 2) {
      add(i, N + 1);
      N += x;
    } else {
      scanf("%lld", &y);
      b[i] += x;
      s[i] += y;
      pop(i);
    }
    printf("%d %lld\n", st[tp].x, calc(st[tp], i));
  }
  return 0;
}
