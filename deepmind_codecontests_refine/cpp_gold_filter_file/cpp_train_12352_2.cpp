#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, m, k, t;
long long a[maxn];
struct seg {
  long long ma;
  bool f1, f2;
  void upd(int id) {
    ma = max(a[id - 1], -a[id]);
    f1 = (a[id - 1] <= 0 && a[id] >= 0);
    f2 = (a[id - 1] > 0 && a[id] < 0);
  }
} tr[maxn << 2];
void pup(int rt) {
  tr[rt].ma = min(tr[rt << 1].ma, tr[rt << 1 | 1].ma);
  tr[rt].f1 = tr[rt << 1].f1 | tr[rt << 1 | 1].f1;
  tr[rt].f2 = tr[rt << 1].f2 | tr[rt << 1 | 1].f2;
}
void build(int l, int r, int rt) {
  if (l == r) {
    tr[rt].upd(l);
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  pup(rt);
}
void upd(int x, int l, int r, int rt) {
  if (x == l && x == r) {
    tr[rt].upd(x);
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    upd(x, l, mid, rt << 1);
  else
    upd(x, mid + 1, r, rt << 1 | 1);
  pup(rt);
}
bool query1(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return tr[rt].f1;
  int mid = l + r >> 1;
  bool flag = false;
  if (L <= mid) flag |= query1(L, R, l, mid, rt << 1);
  if (mid + 1 <= R) flag |= query1(L, R, mid + 1, r, rt << 1 | 1);
  return flag;
}
int query2(int L, int R, int l, int r, int rt) {
  if (!tr[rt].f2) return -1;
  if (l == r) return tr[rt].f2 ? l : -1;
  int mid = l + r >> 1;
  if (L <= l && r <= R) {
    if (tr[rt << 1].f2)
      return query2(L, R, l, mid, rt << 1);
    else
      return query2(L, R, mid + 1, r, rt << 1 | 1);
  } else if (R <= mid)
    return query2(L, R, l, mid, rt << 1);
  else if (L > mid)
    return query2(L, R, mid + 1, r, rt << 1 | 1);
  else {
    int ret = query2(L, R, l, mid, rt << 1);
    if (ret == -1) return query2(L, R, mid + 1, r, rt << 1 | 1);
    return ret;
  }
}
long long query3(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return tr[rt].ma;
  int mid = l + r >> 1;
  long long ret = 1e18;
  if (L <= mid) ret = min(ret, query3(L, R, l, mid, rt << 1));
  if (mid + 1 <= R) ret = min(ret, query3(L, R, mid + 1, r, rt << 1 | 1));
  return ret;
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  long long sum = 0;
  for (i = 1; i < n; i++) a[i] -= a[i + 1], sum += abs(a[i]);
  build(2, n - 1, 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, l, r, x;
    scanf("%d%d%d%d", &op, &l, &r, &x);
    if (op == 1) {
      long long ret = -1e18;
      if (l == 1) ret = max(ret, sum - abs(a[1]) + abs(a[1] + x)), l++;
      if (r == n) ret = max(ret, sum - abs(a[n - 1]) + abs(a[n - 1] - x)), r--;
      if (l > r) {
        printf("%lld\n", ret);
        continue;
      }
      bool f = query1(l, r, 2, n - 1, 1);
      int pos = query2(l, r, 2, n - 1, 1);
      long long mi = 1e18;
      if (pos != -1) {
        if (pos - 1 >= l) mi = min(mi, query3(l, pos - 1, 2, n - 1, 1));
        if (pos + 1 <= r) mi = min(mi, query3(pos + 1, r, 2, n - 1, 1));
      } else
        mi = min(mi, query3(l, r, 2, n - 1, 1));
      if (f) ret = max(ret, sum + 2 * x);
      if (!f && mi != 1e18) ret = max(ret, sum + 2 * max(0LL, x - mi));
      if (!f && pos != -1) {
        if (min(-a[pos], a[pos - 1]) >= x)
          ret = max(ret, sum - 2 * x);
        else if (max(-a[pos], a[pos - 1]) >= x)
          ret = max(ret, sum - 2 * min(-a[pos], a[pos - 1]));
        else
          ret = max(ret, sum + 2 * x + 2 * a[pos] - 2 * a[pos - 1]);
      }
      printf("%lld\n", ret);
    } else {
      if (l > 1) {
        sum -= abs(a[l - 1]);
        a[l - 1] -= x;
        sum += abs(a[l - 1]);
      }
      if (l - 1 >= 2) upd(l - 1, 2, n - 1, 1);
      if (l >= 2) upd(l, 2, n - 1, 1);
      if (r < n) {
        sum -= abs(a[r]);
        a[r] += x;
        sum += abs(a[r]);
      }
      if (r + 1 <= n - 1) upd(r + 1, 2, n - 1, 1);
      if (r <= n - 1) upd(r, 2, n - 1, 1);
    }
  }
  return 0;
}
