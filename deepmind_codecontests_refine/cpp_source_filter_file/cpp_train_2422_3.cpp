#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<int> val;
int a[N], h[N];
double l[N], r[N];
int b[N], z[N];
double c[N << 2];
void push(int x) {
  val.push_back(x);
  val.push_back(x - 1);
  val.push_back(x + 1);
}
int find(int x) { return lower_bound(val.begin(), val.end(), x) - val.begin(); }
void update(int ql, int qr, double d, int l, int r, int rt) {
  if (ql <= l && r <= qr) {
    c[rt] *= d;
    return;
  }
  int m = (l + r) >> 1;
  if (ql <= m) update(ql, qr, d, l, m, (rt << 1));
  if (qr > m) update(ql, qr, d, m + 1, r, (rt << 1 | 1));
}
double query(int q, double d, int l, int r, int rt) {
  d *= c[rt];
  if (l == r) return d;
  int m = (l + r) >> 1;
  if (q <= m)
    return query(q, d, l, m, (rt << 1));
  else
    return query(q, d, m + 1, r, (rt << 1 | 1));
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%lf%lf", &a[i], &h[i], &l[i], &r[i]);
    l[i] /= 100;
    r[i] /= 100;
    push(a[i]);
    push(a[i] + h[i]);
    push(a[i] - h[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", b + i, z + i);
    push(b[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  int sz = val.size();
  for (int i = 0; i < N * 4; i++) c[i] = 1;
  for (int i = 0; i < n; i++) {
    int p1 = find(a[i] - h[i]);
    int p2 = find(a[i]);
    int p3 = find(a[i] + h[i]);
    update(p1, p2 - 1, 1 - l[i], 0, sz - 1, 1);
    update(p2 + 1, p3, 1 - r[i], 0, sz - 1, 1);
  }
  double ans = 0;
  for (int i = 0; i < m; i++) {
    int p = find(b[i]);
    ans += query(p, 1, 0, sz - 1, 1) * z[i];
  }
  printf("%.10f\n", ans);
  return 0;
}
