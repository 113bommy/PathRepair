#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int T[N << 2], a[N], n, m, flag;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void Build(int o, int l, int r) {
  if (l == r) {
    T[o] = a[l];
    return;
  }
  int mid = l + r >> 1;
  Build(o << 1, l, mid);
  Build(o << 1 | 1, mid + 1, r);
  T[o] = gcd(T[o << 1], T[o << 1 | 1]);
  return;
}
void Change(int o, int l, int r, int pos, int d) {
  if (l == r) {
    T[o] = d;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    Change(o << 1, l, mid, pos, d);
  else
    Change(o << 1 | 1, mid + 1, r, pos, d);
  T[o] = gcd(T[o << 1], T[o << 1 | 1]);
  return;
}
int Query(int o, int l, int r, int L, int R, int d) {
  if (flag == 2) return 2;
  if (l == r) {
    if (T[o] % d == 0) return 0;
    return 1;
  }
  int mid = l + r >> 1;
  if (L <= l && r <= R) {
    if (T[o] % d == 0) return 0;
    if (T[o << 1] % d != 0 && T[o << 1 | 1] % d != 0) {
      flag = 2;
      return 2;
    }
    if (T[o << 1] % d != 0) return Query(o << 1, l, mid, L, R, d);
    if (T[o << 1 | 1] % d != 0) return Query(o << 1 | 1, mid + 1, r, L, R, d);
  }
  if (R <= mid)
    return Query(o << 1, l, mid, L, R, d);
  else if (L > mid)
    return Query(o << 1 | 1, mid + 1, r, L, R, d);
  else {
    int f1 = Query(o << 1, l, mid, L, R, d);
    int f2 = Query(o << 1 | 1, mid + 1, r, L, R, d);
    flag = min(f1 + f2, 2);
    return flag;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  Build(1, 1, n);
  scanf("%d", &m);
  for (int typ, l, r, x, i = 1; i <= m; i++) {
    scanf("%d", &typ);
    flag = 0;
    if (typ == 1) {
      scanf("%d%d%d", &l, &r, &x);
      Query(1, 1, n, l, r, x);
      if (flag == 2)
        printf("NO\n");
      else
        printf("YES\n");
    } else {
      scanf("%d%d", &l, &x);
      Change(1, 1, n, l, x);
    }
  }
  return 0;
}
