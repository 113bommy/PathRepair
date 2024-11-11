#include <bits/stdc++.h>
using namespace std;
double A[150005];
int x[150005];
double P[150005];
struct node {
  double sum, ans, ll, rr;
} tree[150005 << 2];
node pushup(node &L, node &R) {
  node res;
  res.ll = max(L.ll, L.sum + R.ll);
  res.rr = max(R.rr, R.sum + L.rr);
  res.sum = L.sum + R.sum;
  res.ans = max(L.ans, R.ans);
  res.ans = max(res.ans, L.rr + R.ll);
  return res;
}
void build(int id, int L, int R) {
  if (L == R) {
    tree[id].ans = tree[id].sum = tree[id].ll = tree[id].rr = A[L];
  } else {
    int mid = (L + R) >> 1;
    build(id << 1, L, mid);
    build(id << 1 | 1, mid + 1, R);
    tree[id] = pushup(tree[id << 1], tree[id << 1 | 1]);
  }
}
node que(int id, int L, int R, int l, int r) {
  if (l <= L && R <= r) return tree[id];
  int mid = (L + R) >> 1;
  if (r <= mid)
    return que(id << 1, L, mid, l, r);
  else if (l > mid)
    return que(id << 1 | 1, mid + 1, R, l, r);
  else {
    int mid = (L + R) >> 1;
    node Lt, Rt;
    Lt = que(id << 1, L, mid, l, r);
    Rt = que(id << 1 | 1, mid + 1, R, l, r);
    return pushup(Lt, Rt);
  }
}
int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i < n; i++) scanf("%lf", &P[i]);
  for (int i = 1; i < n; i++) A[i] = (x[i + 1] - x[i]) / 2.0 - P[i] / 100.0 * c;
  build(1, 1, n - 1);
  double ans = 0;
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    r--;
    double tmp = que(1, 1, n - 1, l, r).ans;
    if (tmp > 0) ans += tmp;
  }
  printf("%.9lf\n", ans);
  return 0;
}
