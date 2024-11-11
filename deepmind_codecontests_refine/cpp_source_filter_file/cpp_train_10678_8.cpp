#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int maxn = 100000 + 5;
int lazy[maxn << 2];
int sum[maxn << 2];
void PushUp(int rt) { sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]); }
void PushDown(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    sum[rt << 1] += lazy[rt];
    sum[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
}
void update(int x, int c, int l, int r, int rt) {
  if (r <= x) {
    lazy[rt] += c;
    sum[rt] += c;
    return;
  }
  PushDown(rt);
  int m = (l + r) >> 1;
  update(x, c, l, m, rt << 1);
  if (m < x) update(x, c, m + 1, r, rt << 1 | 1);
  PushUp(rt);
}
int query(int l, int r, int rt) {
  if (l == r) {
    return sum[rt] ? l : 0;
  }
  PushDown(rt);
  int m = (l + r) >> 1;
  return sum[rt << 1 | 1] > 0 ? query(m + 1, r, rt << 1 | 1)
                              : query(l, m, rt << 1);
}
int sv[maxn];
int main() {
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int p, tp;
    scanf("%d%d", &p, &tp);
    if (!tp) {
      update(p, -1, 1, m, 1);
    } else {
      int tmp;
      scanf("%d", &tmp);
      sv[p] = tmp;
      update(p, 1, 1, m, 1);
    }
    int ret = query(1, m, 1);
    if (sv[ret] <= 0)
      printf("-1\n");
    else
      printf("%d\n", sv[ret]);
  }
  return 0;
}
