#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
const int MAXN = 310000;
struct Seg {
  double sum, left, right, best;
  Seg(){};
  Seg(double x) : sum(x) { left = right = best = max(x, 0.0); }
};
int x[MAXN];
int p[MAXN];
int a[MAXN];
int b[MAXN];
Seg tval[MAXN];
Seg tree[MAXN];
Seg merge(Seg l, Seg r) {
  Seg res;
  res.sum = l.sum + r.sum;
  res.left = max(l.left, l.sum + r.left);
  res.right = max(r.right, r.sum + l.right);
  res.best = max(l.right + r.left, max(l.best, r.best));
  return res;
}
void build(int k, int l, int r) {
  if (l == r - 1) {
    tree[k] = tval[l];
  } else {
    int m = (l + r) / 2;
    build(k * 2 + 1, l, m);
    build(k * 2 + 2, m, r);
    tree[k] = merge(tree[k * 2 + 1], tree[k * 2 + 2]);
  }
}
Seg query(int a, int b, int k, int l, int r) {
  if (a <= l && r <= b) {
    return tree[k];
  } else if (r <= a || b <= l) {
    return Seg(-1e10);
  } else {
    int m = (l + r) / 2;
    return merge(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
  }
}
int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < n - 1; i++) scanf("%d", &p[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    a[i]--, b[i]--;
  }
  for (int i = 0; i < n - 1; i++) {
    tval[i] = (x[i + 1] - x[i]) / 2.0 - c * p[i] / 100.0;
  }
  build(0, 0, n - 1);
  double res = 0;
  for (int i = 0; i < m; i++) {
    res += query(a[i], b[i], 0, 0, n - 1).best;
  }
  printf("%lf\n", res);
  return 0;
}
