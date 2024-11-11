#include <bits/stdc++.h>
using namespace std;
long long a[444444], cot[444444];
void pushdown(int rt) {
  if (cot[rt]) {
    cot[rt << 1] = cot[rt];
    cot[rt << 1 | 1] = cot[rt];
    a[rt << 1] = cot[rt];
    a[rt << 1 | 1] = cot[rt];
    cot[rt] = 0;
  }
}
void pushup(int rt) { a[rt] = max(a[rt << 1], a[rt << 1 | 1]); }
void build(int L, int R, int rt) {
  cot[rt] = 0;
  if (L == R) {
    scanf("%I64d", &a[rt]);
    return;
  }
  int m;
  m = (L + R) >> 1;
  build(L, m, rt << 1);
  build(m + 1, R, rt << 1 | 1);
  pushup(rt);
}
void update(int L, int R, int l, int r, int c, int rt) {
  if (l <= L && R <= r) {
    cot[rt] = c;
    a[rt] = c;
    return;
  }
  pushdown(rt);
  int m;
  m = (L + R) >> 1;
  if (l <= m) update(L, m, l, r, c, rt << 1);
  if (r > m) update(m + 1, R, l, r, c, rt << 1 | 1);
  pushup(rt);
}
long long query(int L, int R, int l, int r, int rt) {
  long long ret = 0;
  if (l <= L && R <= r) return a[rt];
  pushdown(rt);
  int m;
  m = (L + R) >> 1;
  if (l <= m) ret = query(L, m, l, r, rt << 1);
  if (r > m) ret = max(ret, query(m + 1, R, l, r, rt << 1 | 1));
  return ret;
}
int main() {
  int n, m;
  while (scanf("%d", &n) != EOF) {
    build(1, n, 1);
    scanf("%d", &m);
    while (m--) {
      long long w, h;
      scanf("%I64d%I64d", &w, &h);
      long long tmp = query(1, n, 1, w, 1);
      update(1, n, 1, w, tmp + h, 1);
      printf("%I64d\n", tmp);
    }
  }
}
