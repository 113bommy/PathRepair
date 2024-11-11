#include <bits/stdc++.h>
using namespace std;
int n, m, c;
const int MAXN = 150000;
int x[MAXN];
int d[MAXN];
int p[MAXN];
struct segm {
  long long mx, mxp, mxs, sum;
  void join(const segm& lc, const segm& rc) {
    mxp = max(lc.mxp, lc.sum + rc.mxp);
    mxs = max(rc.mxs, lc.mxs + rc.sum);
    sum = lc.sum + rc.sum;
    mx = max(max(max(mxp, mxs), max(sum, lc.mxs + rc.mxp)), max(lc.mx, rc.mx));
  }
};
struct ST {
  int l, r;
  int lc, rc;
  segm u;
} s[MAXN * 2];
int initT(int l, int r) {
  static int cntST = 0;
  int it = ++cntST;
  s[it].l = l, s[it].r = r;
  if (l == r) {
    s[it].u.sum = (d[s[it].l] * 50LL - c * 1LL * p[s[it].l]);
    s[it].u.mx = s[it].u.mxs = s[it].u.mxp = max(0LL, s[it].u.sum);
    s[it].lc = s[it].rc = 0;
  } else {
    int mid = (l + r) / 2;
    s[it].lc = initT(l, mid);
    s[it].rc = initT(mid + 1, r);
    s[it].u.join(s[s[it].lc].u, s[s[it].rc].u);
  }
  return it;
}
segm getRes(int it, int l, int r) {
  if (l <= s[it].l && s[it].r <= r)
    return s[it].u;
  else {
    if (r <= s[s[it].lc].r) return getRes(s[it].lc, l, r);
    if (s[s[it].rc].l <= l) return getRes(s[it].rc, l, r);
    segm tmp;
    tmp.join(getRes(s[it].lc, l, r), getRes(s[it].rc, l, r));
    return tmp;
  }
}
long long addPass(int root, int l, int r) { return getRes(root, l, r).mx; }
int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  n--;
  for (int i = 0; i < n; i++) d[i] = x[i + 1] - x[i];
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  int root = initT(0, n);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b -= 2;
    ans += addPass(root, a, b);
  }
  printf("%.10Lf\n", ans / (long double)100.0);
  return 0;
}
