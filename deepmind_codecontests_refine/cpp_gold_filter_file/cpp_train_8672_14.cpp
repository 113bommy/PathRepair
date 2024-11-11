#include <bits/stdc++.h>
using namespace std;
const int N = 150005;
struct Node {
  int left, right;
  double maxsum, lsum, rsum, sum;
} L[N << 2];
int n, m, c, x[N], p[N];
double val[N];
void push_up(int step) {
  L[step].sum = L[step << 1].sum + L[step << 1 | 1].sum;
  L[step].maxsum = max(max(L[step << 1].maxsum, L[step << 1 | 1].maxsum),
                       L[step << 1].rsum + L[step << 1 | 1].lsum);
  L[step].lsum =
      max(L[step << 1].lsum, L[step << 1].sum + L[step << 1 | 1].lsum);
  L[step].rsum =
      max(L[step << 1 | 1].rsum, L[step << 1 | 1].sum + L[step << 1].rsum);
}
void build(int step, int l, int r) {
  L[step].left = l;
  L[step].right = r;
  if (l == r) {
    L[step].maxsum = L[step].lsum = L[step].rsum = L[step].sum = val[l];
    return;
  }
  int m = (l + r) >> 1;
  build(step << 1, l, m);
  build(step << 1 | 1, m + 1, r);
  push_up(step);
}
double query_sum(int step, int l, int r) {
  if (L[step].left == l && L[step].right == r) {
    return L[step].sum;
  }
  int m = (L[step].left + L[step].right) >> 1;
  if (r <= m)
    return query_sum(step << 1, l, r);
  else if (l > m)
    return query_sum(step << 1 | 1, l, r);
  else
    return query_sum(step << 1, l, m) + query_sum(step << 1 | 1, m + 1, r);
}
double query_left(int step, int l, int r) {
  if (L[step].left == l && L[step].right == r) {
    return L[step].lsum;
  }
  int m = (L[step].left + L[step].right) >> 1;
  if (r <= m)
    return query_left(step << 1, l, r);
  else if (l > m)
    return query_left(step << 1 | 1, l, r);
  else
    return max(
        query_left(step << 1, l, m),
        query_sum(step << 1, l, m) + query_left(step << 1 | 1, m + 1, r));
}
double query_right(int step, int l, int r) {
  if (L[step].left == l && L[step].right == r) {
    return L[step].rsum;
  }
  int m = (L[step].left + L[step].right) >> 1;
  if (r <= m)
    return query_right(step << 1, l, r);
  else if (l > m)
    return query_right(step << 1 | 1, l, r);
  else
    return max(
        query_right(step << 1 | 1, m + 1, r),
        query_sum(step << 1 | 1, m + 1, r) + query_right(step << 1, l, m));
}
double query(int step, int l, int r) {
  if (L[step].left == l && L[step].right == r) {
    return L[step].maxsum;
  }
  int m = (L[step].left + L[step].right) >> 1;
  if (r <= m)
    return query(step << 1, l, r);
  else if (l > m)
    return query(step << 1 | 1, l, r);
  else {
    return max(
        max(query(step << 1, l, m), query(step << 1 | 1, m + 1, r)),
        query_left(step << 1 | 1, m + 1, r) + query_right(step << 1, l, m));
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d", &p[i]);
    val[i] = (x[i + 1] - x[i]) / 2.0 - (p[i] * 0.01 * c);
  }
  build(1, 1, n - 1);
  double ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    ans += max(0.0, query(1, a, b - 1));
  }
  printf("%.10f\n", ans);
  return 0;
}
