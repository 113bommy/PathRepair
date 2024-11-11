#include <bits/stdc++.h>
using namespace std;
struct node {
  long long ls, rs, sum, cnt;
} t[(long long)(1e5 + 5) * 50];
long long a[(long long)(1e5 + 5)];
long long tot, rt, n, m;
void update(long long &cur, long long l, long long r, long long x, long long v,
            long long vc) {
  if (!cur) cur = ++tot;
  if (l == r) {
    t[cur].sum += v;
    t[cur].cnt += vc;
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid)
    update(t[cur].ls, l, mid, x, v, vc);
  else
    update(t[cur].rs, mid + 1, r, x, v, vc);
  t[cur].sum = t[t[cur].ls].sum + t[t[cur].rs].sum;
  t[cur].cnt = t[t[cur].ls].cnt + t[t[cur].rs].cnt;
}
long long query(long long cur, long long l, long long r, long long cl,
                long long cr, bool fl) {
  if (!cur) return 0;
  if (r == (long long)(1e9) && cr > r) cr = (long long)(1e9);
  if (cl <= l && r <= cr) return fl ? t[cur].sum : t[cur].cnt;
  long long mid = (l + r) >> 1, res = 0;
  if (cl <= mid) res = query(t[cur].ls, l, mid, cl, cr, fl);
  if (cr > mid) res += query(t[cur].rs, mid + 1, r, cl, cr, fl);
  return res;
}
double solve(long long x) {
  double l = 0.0, r = 1e15, res = 0.0;
  while (l < r - (1e-4)) {
    double mid = (l + r) / 2.0;
    if ((query(rt, 0, (long long)(1e9), 0, mid, 1) + x) <=
        query(rt, 0, (long long)(1e9), 0, mid, 0) * mid)
      res = r = mid;
    else
      l = mid;
  }
  return res;
}
long long rd() {
  long long f = 1, sum = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    sum = (sum << 3) + (sum << 1) + ch - '0';
    ch = getchar();
  }
  return sum * f;
}
signed main() {
  long long op, x, y;
  n = rd();
  m = rd();
  for (long long i = 1; i <= n; i++)
    a[i] = rd(), update(rt, 0, (long long)(1e9), a[i], a[i], 1);
  while (m--) {
    op = rd();
    if (op == 1) {
      x = rd();
      y = rd();
      update(rt, 0, (long long)(1e9), a[x], -a[x], -1);
      update(rt, 0, (long long)(1e9), y, a[x] = y, 1);
    } else {
      x = rd();
      printf("%.4lf\n", solve(x));
    }
  }
  return 0;
}
