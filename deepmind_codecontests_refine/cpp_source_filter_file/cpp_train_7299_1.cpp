#include <bits/stdc++.h>
using namespace std;
int const N = 100000, inf = 1e9, K = 300000;
pair<pair<int, int>, int> sg[K];
int n, m, k;
struct S {
  int v;
  S *l, *r;
  S() : v(inf), l(0), r(0) {}
  int va() { return max((l ? l->v : inf), (r ? r->v : inf)); }
};
S *R[K + 1];
S *up(S *R, int va, int i, int l = 1, int r = n) {
  S *v = new S();
  if (!R) R = v;
  v->l = R->l;
  v->r = R->r;
  v->v = R->v;
  if (l == r) {
    v->v = min(va, v->v);
    return v;
  }
  int m = l + r >> 1;
  if (i <= m)
    v->l = up(R->l, va, i, l, m);
  else
    v->r = up(R->r, va, i, m + 1, r);
  v->v = v->va();
  return v;
}
int get(S *v, int x, int y, int l = 1, int r = n) {
  if (l > y || r < x) return 0;
  if (!v) return inf;
  if (l >= x && r <= y) return v->v;
  int m = l + r >> 1;
  return max(get(v->l, x, y, l, m), get(v->r, x, y, m + 1, r));
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < (int)(k); ++i)
    scanf("%d%d%d", &sg[i].first.first, &sg[i].first.second, &sg[i].second);
  sort(sg, sg + k);
  for (int i = k - 1; i >= 0; --i)
    R[i] = up(R[i + 1], sg[i].first.second, sg[i].second);
  for (int i = 0; i < (int)(m); ++i) {
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    int z = lower_bound(sg, sg + k, make_pair(make_pair(x, 0), 0)) - sg;
    printf("%s\n", get(R[z], a, b) <= y ? "yes" : "no");
    fflush(stdout);
  }
}
