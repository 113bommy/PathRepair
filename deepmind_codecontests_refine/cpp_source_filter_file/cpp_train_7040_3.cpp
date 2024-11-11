#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int L[maxn << 2], R[maxn << 2];
double sum[maxn << 2], add[maxn << 2], mul[maxn << 2];
void pushup(int i) { sum[i] = sum[i * 2] + sum[i * 2 + 1]; }
void pushdown(int i) {
  sum[i * 2] = sum[i * 2] * mul[i] + add[i] * (R[i * 2] - L[i * 2] + 1);
  sum[i * 2 + 1] =
      sum[i * 2 + 1] * mul[i] + add[i] * (R[i * 2 + 1] - L[i * 2 + 1] + 1);
  add[i * 2] = add[i * 2] * mul[i] + add[i];
  add[i * 2 + 1] = add[i * 2 + 1] * mul[i] + add[i];
  mul[i * 2] = mul[i] * mul[i * 2];
  mul[i * 2 + 1] = mul[i * 2 + 1] * mul[i];
  mul[i] = 1;
  add[i] = 0;
}
void build(int i, int l, int r) {
  L[i] = l;
  R[i] = r;
  add[i] = 0;
  mul[i] = 1;
  if (l == r) {
    cin >> sum[i];
    return;
  }
  int mid = (l + r) >> 1;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  pushup(i);
}
double query(int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return sum[i];
  }
  pushdown(i);
  int mid = (l + r) >> 1;
  double res = 0;
  if (x <= mid) {
    res += query(i * 2, l, mid, x, y);
  } else if (y > mid) {
    res += query(i * 2 + 1, mid + 1, r, x, y);
  }
  return res;
}
void update1(int i, int l, int r, int x, int y, double v) {
  if (x <= l && r <= y) {
    sum[i] += v * (r - l + 1);
    add[i] += v;
    return;
  }
  pushdown(i);
  int mid = (l + r) >> 1;
  if (x <= mid) update1(i * 2, l, mid, x, y, v);
  if (y > mid) update1(i * 2 + 1, mid + 1, r, x, y, v);
  pushup(i);
}
void update2(int i, int l, int r, int x, int y, double v) {
  if (x <= l && r <= y) {
    add[i] *= v;
    sum[i] *= v;
    mul[i] *= v;
    return;
  }
  pushdown(i);
  int mid = (l + r) >> 1;
  if (x <= mid) update2(i * 2, l, mid, x, y, v);
  if (y > mid) update2(i * 2 + 1, mid + 1, r, x, y, v);
  pushup(i);
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  build(1, 1, n);
  while (q--) {
    int l1, r1, l2, r2;
    int id;
    scanf("%d", &id);
    if (id == 1) {
      scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
      double sum1 = query(1, 1, n, l1, r1);
      double sum2 = query(1, 1, n, l2, r2);
      double len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
      update2(1, 1, n, l1, r1, (len1 - 1) / len1);
      update2(1, 1, n, l2, r2, (len2 - 1) / len2);
      update1(1, 1, n, l1, r1, sum2 / (len1 * len2));
      update1(1, 1, n, l2, r2, sum1 / (len1 * len2));
    } else {
      scanf("%d%d", &l1, &r1);
      printf("%.7lf\n", query(1, 1, n, l1, r1));
    }
  }
  return 0;
}
