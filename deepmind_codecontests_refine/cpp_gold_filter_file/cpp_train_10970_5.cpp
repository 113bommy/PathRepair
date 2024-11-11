#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 50;
struct tree {
  int l, r;
  pair<int, int> vmax;
  tree *lc, *rc;
  tree(int _l, int _r) : l(_l), r(_r), vmax(pair<int, int>(0, 0)) {
    lc = rc = 0;
  }
  void init() {
    if (l != r) {
      int m = (l + r) / 2;
      (lc = new tree(l, m))->init();
      (rc = new tree(m + 1, r))->init();
    }
  }
  void modify(int p, pair<int, int> mv) {
    vmax = max(vmax, mv);
    if (l == r) return;
    (p <= ((l + r) >> 1) ? lc : rc)->modify(p, mv);
  }
  pair<int, int> query(int ql, int qr) {
    if (ql <= l && r <= qr) return vmax;
    int m = (l + r) >> 1;
    pair<int, int> res(0, 0);
    if (ql <= m) res = lc->query(ql, qr);
    if (qr > m) res = max(res, rc->query(ql, qr));
    return res;
  }
} * rt;
pair<pair<int, int>, int> axis[N];
struct truck {
  int v, c, l, r;
} A[N];
int n, dp[N], apos[N], pre[N];
vector<int> resvec;
int solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &A[i].v, &A[i].c, &A[i].l, &A[i].r);
    axis[i] =
        pair<pair<int, int>, int>(pair<int, int>(A[i].l + A[i].c, A[i].r), i);
  }
  sort(axis + 1, axis + 1 + n);
  for (int i = 1; i <= n; ++i) apos[axis[i].second] = i;
  (rt = new tree(1, n))->init();
  for (int i = 1; i <= n; ++i) {
    if (A[i].l == 0)
      dp[i] = A[i].v;
    else {
      auto p = equal_range(
          axis + 1, axis + 1 + n,
          pair<pair<int, int>, int>(pair<int, int>(A[i].l, A[i].r + A[i].c), 0),
          [](const pair<pair<int, int>, int> &a,
             const pair<pair<int, int>, int> &b) { return a.first < b.first; });
      int l = p.first - axis, r = p.second - axis - 1;
      if (l > r) continue;
      pair<int, int> z = rt->query(l, r);
      if (!z.first)
        dp[i] = 0;
      else {
        dp[i] = z.first + A[i].v;
        pre[i] = z.second;
      }
    }
    rt->modify(apos[i], pair<int, int>(dp[i], i));
  }
  pair<int, int> res(0, 0);
  for (int i = 1; i <= n; ++i)
    if (A[i].r == 0 && dp[i]) res = max(res, pair<int, int>(dp[i], i));
  fprintf(stderr, "%d\n", res.first);
  for (int z = res.second; z; z = pre[z]) resvec.push_back(z);
  printf("%d\n", int(resvec.size()));
  for (auto i = resvec.rbegin(); i != resvec.rend(); ++i) printf("%d ", *i);
  printf("\n");
  return 0;
}
int main() { return solve(); }
