#include <bits/stdc++.h>
using namespace std;
struct Segment {
  int tp, mx[300005 << 2];
  inline int cmp(int x, int y) { return tp ? min(x, y) : max(x, y); }
  void build(int l, int r, int rt, int *a) {
    if (l == r) {
      mx[rt] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1, a), build(m + 1, r, rt << 1 | 1, a);
    mx[rt] = cmp(mx[rt << 1], mx[rt << 1 | 1]);
  }
  int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return mx[rt];
    int m = (l + r) >> 1;
    if (R <= m) return query(L, R, l, m, rt << 1);
    if (L > m) return query(L, R, m + 1, r, rt << 1 | 1);
    return cmp(query(L, R, l, m, rt << 1), query(L, R, m + 1, r, rt << 1 | 1));
  }
} mn[18], mx[18];
int r[300005], L[18][300005], R[18][300005], n;
int main() {
  scanf("%d", &n);
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &r[i]), r[i + n] = r[i + (n << 1)] = r[i];
  for (int i = 1; i <= n * 3; i++)
    L[0][i] = max(1, i - r[i]), R[0][i] = min(n * 3, i + r[i]);
  for (int i = 1; i <= 17; i++) {
    mn[i - 1].tp = 1;
    mn[i - 1].build(1, n * 3, 1, L[i - 1]);
    mx[i - 1].build(1, n * 3, 1, R[i - 1]);
    for (int j = 1; j <= n * 3; j++)
      L[i][j] = mn[i - 1].query(L[i - 1][j], R[i - 1][j], 1, n * 3, 1),
      R[i][j] = mx[i - 1].query(L[i - 1][j], R[i - 1][j], 1, n * 3, 1);
  }
  mn[17].tp = 1;
  mn[17].build(1, n * 3, 1, L[17]);
  mx[17].build(1, n * 3, 1, R[17]);
  for (int i = n + 1; i <= n << 1; i++) {
    int l = i, r = i, ans = 0;
    for (int j = 17; ~j; j--) {
      int tl = mn[j].query(l, r, 1, n * 3, 1),
          tr = mx[j].query(l, r, 1, n * 3, 1);
      if (tr - tl + 1 < n) l = tl, r = tr, ans |= 1 << j;
    }
    printf("%d ", ans + 1);
  }
}
