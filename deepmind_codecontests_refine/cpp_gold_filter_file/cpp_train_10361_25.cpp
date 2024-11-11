#include <bits/stdc++.h>
using namespace std;
struct node {
  int id;
  long long x;
} a[111111];
long long f[4 * 111111];
bool cmp(node a, node b) { return a.x == b.x ? a.id > b.id : a.x < b.x; }
int pos;
long long X;
long long qry(int l, int r, int p) {
  int mid = (l + r) >> 1;
  if (pos == r) return f[p];
  if (pos <= mid) return qry(l, mid, 2 * p);
  if (pos > mid) return max(f[2 * p], qry(mid + 1, r, 2 * p + 1));
}
long long add(int l, int r, int p) {
  int mid = (l + r) >> 1;
  if (l == r) return f[p] = X;
  if (pos <= mid)
    return f[p] = max(f[p], add(l, mid, 2 * p));
  else
    return f[p] = max(f[p], add(mid + 1, r, 2 * p + 1));
}
int main() {
  int n;
  long long l, h;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &l, &h);
    a[i].id = i;
    a[i].x = ((l) * (l)) * h;
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) {
    pos = a[i].id;
    long long temp = qry(0, n - 1, 1) + a[i].x;
    X = temp;
    add(0, n - 1, 1);
  }
  printf("%.6lf\n", f[1] * acos(-1.0));
  return 0;
}
