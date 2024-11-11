#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5;
int n, ans[N];
long long mi[4 * N], pos[4 * N], v[N], lz[4 * N];
void build(int p, int l, int r) {
  if (l == r) {
    mi[p] = v[l], pos[p] = l;
    return;
  }
  int m = (l + r) / 2;
  build(2 * p, l, m);
  build(2 * p + 1, m + 1, r);
  mi[p] = min(mi[2 * p], mi[2 * p + 1]);
  if (mi[p] == mi[2 * p + 1])
    pos[p] = pos[2 * p + 1];
  else
    pos[p] = pos[2 * p];
}
void push(int p, int l, int r) {
  if (lz[p]) {
    mi[p] += lz[p];
    if (l != r) {
      lz[2 * p] += lz[p];
      lz[2 * p + 1] += lz[p];
    }
    lz[p] = 0;
  }
}
pair<long long, long long> query(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if (r < i or l > j) assert(0);
  if (i <= l and r <= j) return {mi[p], pos[p]};
  int m = (l + r) / 2;
  if (m > j) return query(2 * p, l, m, i, j);
  if (m < i) return query(2 * p + 1, m + 1, r, i, j);
  pair<long long, long long> a = query(2 * p, l, m, i, j);
  pair<long long, long long> b = query(2 * p + 1, m + 1, r, i, j);
  if (a.first < b.first)
    return a;
  else
    return b;
}
void update(int p, int l, int r, int i, int j, long long v) {
  push(p, l, r);
  if (r < i or l > j) return;
  if (i <= l and r <= j) {
    lz[p] = v;
    push(p, l, r);
    return;
  }
  update(2 * p, l, (l + r) / 2, i, j, v);
  update(2 * p + 1, (l + r) / 2 + 1, r, i, j, v);
  mi[p] = min(mi[2 * p], mi[2 * p + 1]);
  if (mi[p] == mi[2 * p + 1])
    pos[p] = pos[2 * p + 1];
  else
    pos[p] = pos[2 * p];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
  build(1, 1, n);
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= n; i++) {
    auto p = query(1, 1, n, 1, n);
    ans[p.second] = i;
    update(1, 1, n, p.second + 1, n, -i);
    update(1, 1, n, p.second, p.second, LINF);
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
