#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
double ary[N], tree[4 * N], lazy_mul[4 * N], lazy_add[4 * N];
long long int n, q;
void push(long long int node, long long int s, long long int e) {
  if (s != e) {
    lazy_mul[(node << 1)] *= lazy_mul[node];
    lazy_mul[(node << 1) + 1] *= lazy_mul[node];
    lazy_add[(node << 1)] =
        lazy_add[(node << 1)] * lazy_mul[node] + lazy_add[node];
    lazy_add[(node << 1) + 1] =
        lazy_add[(node << 1) + 1] * lazy_mul[node] + lazy_add[node];
    long long int m = (s + e) / 2;
    tree[2 * node] *= lazy_mul[node];
    tree[2 * node + 1] *= lazy_mul[node];
    tree[2 * node] += (m - s + 1) * lazy_add[node];
    tree[2 * node + 1] += (e - m) * lazy_add[node];
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  lazy_mul[node] = 1;
  lazy_add[node] = 0;
}
void build(long long int node, long long int s, long long int e) {
  lazy_mul[node] = 1;
  if (s == e)
    tree[node] = ary[s];
  else {
    long long int m = (s + e) / 2;
    build((node << 1), s, m);
    build((node << 1) + 1, m + 1, e);
    tree[node] = tree[(node << 1)] + tree[(node << 1) + 1];
  }
}
double query(long long int node, long long int s, long long int e,
             long long int l, long long int r) {
  if (s > r || e < l) return 0;
  if (s >= l && e <= r) return tree[node];
  push(node, s, e);
  long long int m = (s + e) >> 1;
  double x = query((node << 1), s, m, l, r);
  double y = query((node << 1) + 1, m + 1, e, l, r);
  return x + y;
}
void update(long long int node, long long int s, long long int e,
            long long int l, long long int r, double mul, double add) {
  if (s > e || s > r || e < l) return;
  if (s >= l && e <= r) {
    tree[node] = tree[node] * mul + (e - s + 1) * add;
    lazy_mul[node] *= mul;
    lazy_add[node] = lazy_add[node] * mul + add;
    return;
  }
  push(node, s, e);
  long long int m = (s + e) >> 1;
  update(node << 1, s, m, l, r, mul, add);
  update((node << 1) + 1, m + 1, e, l, r, mul, add);
  tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> q;
  for (long long int i = 0; i < n; ++i) cin >> ary[i];
  build(1, 0, n - 1);
  while (q--) {
    long long int type;
    cin >> type;
    if (type == 1) {
      double l1, l2, r1, r2, x, y;
      cin >> l1 >> r1 >> l2 >> r2;
      l1--, l2--, r1--, r2--;
      double q1 = query(1, 0, n - 1, l1, r1);
      double q2 = query(1, 0, n - 1, l2, r2);
      x = r1 - l1 + 1;
      y = r2 - l2 + 1;
      update(1, 0, n - 1, l1, r1, (x - 1) / x, q2 / (x * y));
      update(1, 0, n - 1, l2, r2, (y - 1) / y, q1 / (x * y));
    } else {
      double l, r;
      cin >> l >> r;
      l--, r--;
      printf("%.7lf\n", query(1, 0, n - 1, l, r));
    }
  }
  return 0;
}
