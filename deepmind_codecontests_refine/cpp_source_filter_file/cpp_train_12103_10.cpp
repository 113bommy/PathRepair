#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  int a[2][2];
  Matrix() { a[0][1] = a[1][0] = a[0][0] = a[1][1] = 0; }
  Matrix operator*(Matrix x) {
    Matrix ans;
    ans.a[0][0] = min(a[0][0] + x.a[0][0], a[0][1] + x.a[1][0]);
    ans.a[0][1] = min(a[0][0] + x.a[0][1], a[0][1] + x.a[1][1]);
    ans.a[1][0] = min(a[1][0] + x.a[0][0], a[1][1] + x.a[1][0]);
    ans.a[1][1] = min(a[1][0] + x.a[0][1], a[1][1] + x.a[1][1]);
    return ans;
  }
} mul[2][4][400010], one;
char s[100010], op[5];
int n, m, a[2][100010], b[2][100010], sum[4][400010], revmark[2][400010];
bool tag[4][400010];
void rev(int k, int rt, int r) {
  revmark[k][rt] ^= r;
  if (r == 1)
    swap(mul[k][0][rt], mul[k][1][rt]), swap(mul[k][2][rt], mul[k][3][rt]);
  if (r == 2)
    swap(mul[k][0][rt], mul[k][2][rt]), swap(mul[k][1][rt], mul[k][3][rt]);
  if (r == 3)
    swap(mul[k][0][rt], mul[k][3][rt]), swap(mul[k][1][rt], mul[k][2][rt]);
}
inline void pushup(int k, int rt) {
  for (int i = 0; i < 4; i++)
    mul[k][i][rt] = mul[k][i][rt * 2 + 1] * mul[k][i][rt * 2];
}
void pushdown(int k, int rt) {
  if (revmark[k][rt]) {
    rev(k, rt * 2, revmark[k][rt]);
    rev(k, rt * 2 + 1, revmark[k][rt]);
    revmark[k][rt] = 0;
  }
}
void build(int k, int rt, int l, int r) {
  if (l == r) {
    if (!k)
      for (int i = 0; i < 4; i++) {
        if (i & 1) a[0][l] ^= 1;
        if (i & 2) a[1][l] ^= 1;
        mul[k][i][rt].a[0][0] = a[0][l] + a[1][l];
        mul[k][i][rt].a[0][1] = a[0][l] + a[1][l] + m;
        mul[k][i][rt].a[1][0] = !a[0][l] + !a[1][l] + m;
        mul[k][i][rt].a[1][1] = !a[0][l] + !a[1][l];
        if (i & 1) a[0][l] ^= 1;
        if (i & 2) a[1][l] ^= 1;
      }
    else
      for (int i = 0; i < 4; i++) {
        if (i & 1) b[0][l] ^= 1;
        if (i & 2) b[1][l] ^= 1;
        mul[k][i][rt].a[0][0] = b[0][l] + b[1][l];
        mul[k][i][rt].a[0][1] = b[0][l] + b[1][l] + n;
        mul[k][i][rt].a[1][0] = !b[0][l] + !b[1][l] + n;
        mul[k][i][rt].a[1][1] = !b[0][l] + !b[1][l];
        if (i & 1) b[0][l] ^= 1;
        if (i & 2) b[1][l] ^= 1;
      }
    return;
  }
  int mid = (l + r) / 2;
  build(k, rt * 2, l, mid);
  build(k, rt * 2 + 1, mid + 1, r);
  pushup(k, rt);
}
void update(int k, int rt, int l, int r, int x, int y, int z) {
  if (l > y || r < x) return;
  if (x <= l && r <= y) return rev(k, rt, z);
  pushdown(k, rt);
  int mid = (l + r) / 2;
  update(k, rt * 2, l, mid, x, y, z);
  update(k, rt * 2 + 1, mid + 1, r, x, y, z);
  pushup(k, rt);
}
Matrix query(int k, int rt, int l, int r, int x, int y) {
  if (x > y) return one;
  if (x <= l && r <= y) return mul[k][0][rt];
  pushdown(k, rt);
  int mid = (l + r) / 2;
  if (y <= mid)
    return query(k, rt * 2, l, mid, x, y);
  else if (x > mid)
    return query(k, rt * 2 + 1, mid + 1, r, x, y);
  else
    return query(k, rt * 2 + 1, mid + 1, r, x, y) *
           query(k, rt * 2, l, mid, x, y);
}
void build2(int k, int rt, int l, int r) {
  if (l == r) return sum[k][rt] = (k & 2) ? a[k & 1][l] : b[k & 1][l], void();
  int mid = (l + r) / 2;
  build2(k, rt * 2, l, mid);
  build2(k, rt * 2 + 1, mid + 1, r);
  sum[k][rt] = sum[k][rt * 2] + sum[k][rt * 2 + 1];
}
void pushdown2(int k, int rt, int l, int r) {
  if (tag[k][rt]) {
    tag[k][rt * 2] ^= 1;
    tag[k][rt * 2 + 1] ^= 1;
    sum[k][rt * 2] = ((l + r) / 2 - l + 1) - sum[k][rt * 2];
    sum[k][rt * 2 + 1] = (r - (l + r) / 2) - sum[k][rt * 2 + 1];
    tag[k][rt] = 0;
  }
}
void update2(int k, int rt, int l, int r, int x, int y) {
  if (l > y || r < x) return;
  if (x <= l && r <= y)
    return sum[k][rt] = (r - l + 1) - sum[k][rt], tag[k][rt] ^= 1, void();
  pushdown2(k, rt, l, r);
  int mid = (l + r) / 2;
  update2(k, rt * 2, l, mid, x, y);
  update2(k, rt * 2 + 1, mid + 1, r, x, y);
  sum[k][rt] = sum[k][rt * 2] + sum[k][rt * 2 + 1];
}
int query2(int k, int rt, int l, int r, int x, int y) {
  if (l > y || r < x) return 0;
  if (x <= l && r <= y) return sum[k][rt];
  pushdown2(k, rt, l, r);
  int mid = (l + r) / 2;
  return query2(k, rt * 2, l, mid, x, y) +
         query2(k, rt * 2 + 1, mid + 1, r, x, y);
}
int solve() {
  int x, y, p, q, ans1, ans2;
  Matrix z;
  x = query2(0, 1, 1, m, 1, m) + a[0][1] + a[1][1];
  y = m + 2 - x;
  p = query2(1, 1, 1, m, 1, m);
  q = m - p;
  z = query(0, 1, 1, n, 2, n);
  ans1 = min(min(z.a[0][0] + x + p, z.a[0][1] + y + p),
             min(z.a[1][0] + x + q, z.a[1][1] + y + q));
  x = query2(2, 1, 1, n, 1, n) + b[0][1] + b[1][1];
  y = n + 2 - x;
  p = query2(3, 1, 1, n, 1, n);
  q = n - p;
  z = query(1, 1, 1, m, 2, m);
  ans2 = min(min(z.a[0][0] + x + p, z.a[0][1] + y + p),
             min(z.a[1][0] + x + q, z.a[1][1] + y + q));
  return min(ans1, ans2);
}
int main() {
  one.a[1][0] = one.a[0][1] = 1e9;
  int q, l, r;
  cin >> n >> m >> q;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[0][i] = (s[i] == 'R');
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[1][i] = (s[i] == 'R');
  scanf("%s", s + 1);
  for (int i = 1; i <= m; i++) b[0][i] = (s[i] == 'R');
  scanf("%s", s + 1);
  for (int i = 1; i <= m; i++) b[1][i] = (s[i] == 'R');
  build(0, 1, 1, n);
  build(1, 1, 1, m);
  build2(0, 1, 1, m);
  build2(1, 1, 1, m);
  build2(2, 1, 1, n);
  build2(3, 1, 1, n);
  printf("%d\n", solve());
  while (q--) {
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'L')
      update(0, 1, 1, n, l, r, 1), update2(2, 1, 1, n, l, r),
          (l == 1 ? a[0][1] ^= 1 : 0);
    if (op[0] == 'R')
      update(0, 1, 1, n, l, r, 2), update2(3, 1, 1, n, l, r),
          (l == 1 ? a[1][1] ^= 1 : 0);
    if (op[0] == 'U')
      update(1, 1, 1, m, l, r, 1), update2(0, 1, 1, m, l, r),
          (l == 1 ? b[0][1] ^= 1 : 0);
    if (op[0] == 'D')
      update(1, 1, 1, m, l, r, 1), update2(1, 1, 1, m, l, r),
          (l == 1 ? b[1][1] ^= 1 : 0);
    printf("%d\n", solve());
  }
  return 0;
}
