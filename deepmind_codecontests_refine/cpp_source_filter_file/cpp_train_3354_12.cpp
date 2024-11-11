#include <bits/stdc++.h>
const int N = 300010;
int n, m;
int a[N];
int last[N];
int mi[N], mx[N];
int sum[N << 2 | 1];
int sum2[N << 2 | 1];
void Change(int l, int r, int rt, int id, int x) {
  if (l == r) {
    sum[rt] = x;
    return;
  }
  int m = (l + r) >> 1;
  if (id <= m)
    Change(l, m, rt << 1, id, x);
  else
    Change(m + 1, r, rt << 1 | 1, id, x);
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int Sum(int l, int r, int rt, int L, int R) {
  if (L <= l && r <= R) return sum[rt];
  int m = (l + r) >> 1;
  int ans = 0;
  if (L <= m) ans += Sum(l, m, rt << 1, L, R);
  if (R > m) ans += Sum(m + 1, r, rt << 1 | 1, L, R);
  return ans;
}
void Change2(int l, int r, int rt, int id, int x) {
  if (l == r) {
    sum2[rt] = x;
    return;
  }
  int m = (l + r) >> 1;
  if (id <= m)
    Change2(l, m, rt << 1, id, x);
  else
    Change2(m + 1, r, rt << 1 | 1, id, x);
  sum2[rt] = sum2[rt << 1] + sum2[rt << 1 | 1];
}
int Sum2(int l, int r, int rt, int L, int R) {
  if (L <= l && r <= R) return sum2[rt];
  int m = (l + r) >> 1;
  int ans = 0;
  if (L <= m) ans += Sum2(l, m, rt << 1, L, R);
  if (R > m) ans += Sum2(m + 1, r, rt << 1 | 1, L, R);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
    if (!last[a[i]]) {
      mx[a[i]] = std::max(mx[a[i]], a[i] + Sum(1, n, 1, a[i] + 1, n));
    } else {
      mx[a[i]] = std::max(mx[a[i]], Sum2(1, m, 1, last[a[i]] + 1, i));
      Change2(1, n, 1, last[a[i]], 0);
    }
    mi[a[i]] = 1;
    last[a[i]] = i;
    Change(1, n, 1, a[i], 1);
    Change2(1, n, 1, i, 1);
  }
  for (int i = 1; i <= n; ++i) {
    if (!mi[i]) {
      mi[i] = i;
      mx[i] = i + Sum(1, n, 1, i + 1, n);
    } else {
      mx[i] = std::max(mx[i], Sum2(1, m, 1, last[i], m));
    }
    printf("%d %d\n", mi[i], mx[i]);
  }
  return 0;
}
