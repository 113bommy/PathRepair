#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct cloud {
  int l, r, c;
  bool operator<(const cloud &a) const { return c < a.c; }
} a[N];
pair<int, int> q[N], op[N * 2];
int n, C, Q, ans[N], qq[N], at[N];
int one[N], oth[N], lim[N];
map<int, int> two[N];
struct SEG {
  int t[N * 4], nn;
  void build(int _n) {
    for (nn = 1; nn <= _n; nn <<= 1)
      ;
    for (int i = (int)(0); i <= (int)(2 * nn - 1); i++) t[i] = 0;
  }
  void change(int x, int v) {
    for (x += nn; x; x >>= 1) t[x] = max(t[x], v);
  }
  int ask(int l, int r) {
    int ans = 0;
    l += nn - 1;
    r += nn + 1;
    for (; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (!(l & 1)) ans = max(ans, t[l ^ 1]);
      if (r & 1) ans = max(ans, t[r ^ 1]);
    }
    return ans;
  }
} TR;
int main() {
  scanf("%d%d", &n, &C);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].c);
  scanf("%d", &Q);
  for (int i = (int)(1); i <= (int)(Q); i++)
    scanf("%d", &q[i].first), q[i].second = i;
  sort(a + 1, a + n + 1);
  sort(q + 1, q + Q + 1);
  int op_top = 2;
  op[1] = pair<int, int>(0, 0);
  op[2] = pair<int, int>(2147480000, 0);
  for (int i = (int)(1); i <= (int)(n); i++) {
    op[++op_top] = pair<int, int>(a[i].l, i);
    op[++op_top] = pair<int, int>(a[i].r, -i);
  }
  sort(op + 1, op + op_top + 1);
  int p = n;
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (; p && a[i].c + a[p].c > C; --p)
      ;
    lim[i] = p;
  }
  int pos = 1, top = 0;
  int free = 0, mxv = 0;
  TR.build(n);
  for (int i = (int)(1); i <= (int)(op_top - 1); i++) {
    int v = op[i + 1].first - op[i].first, p1, p2;
    if (top == 2 && a[p1 = qq[1]].c + a[p2 = qq[2]].c <= C) {
      two[p1][p2] += v;
      two[p2][p1] += v;
      oth[p1] = max(oth[p1], two[p1][p2] + one[p2]);
      oth[p2] = max(oth[p2], two[p1][p2] + one[p1]);
      mxv = max(mxv, one[p1] + one[p2] + two[p1][p2]);
    } else if (top == 1 && a[p1 = qq[1]].c <= C) {
      TR.change(p1, one[p1] += v);
      mxv = max(mxv, one[p1] + oth[p1]);
      if (p1 != 1 && lim[p1])
        mxv = max(mxv, one[p1] + TR.ask(1, min(lim[p1], p1 - 1)));
      if (p1 != n && lim[p1] > p1)
        mxv = max(mxv, one[p1] + TR.ask(p1 + 1, lim[p1]));
    } else if (!top)
      free += v;
    if ((p1 = op[i + 1].second) >= 0)
      qq[at[p1] = ++top] = p1;
    else
      p1 = -p1, at[qq[top]] = at[p1], qq[at[p1]] = qq[top--];
    for (; pos <= Q && q[pos].first <= free + mxv; ++pos)
      ans[q[pos].second] = op[i + 1].first - (free + mxv - q[pos].first);
  }
  for (int i = (int)(1); i <= (int)(Q); i++) printf("%d\n", ans[i]);
}
