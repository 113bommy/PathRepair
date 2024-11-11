#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 5e6 + 5, inf = 1e9;
int n, k, tt;
long long ans;
map<int, int> rt;
struct qq {
  int x, r, q;
} a[N];
struct st {
  int ls, rs, s;
} t[M];
bool cmp(qq x, qq y) { return x.r > y.r; }
void upd(int &x, int l, int r, int p) {
  if (!x) x = ++tt;
  t[x].s++;
  if (l == r) return;
  int mid = l + r >> 1;
  if (p <= mid)
    upd(t[x].ls, l, mid, p);
  else
    upd(t[x].rs, mid + 1, r, p);
}
int qry(int x, int l, int r, int tl, int tr) {
  if (!x) return 0;
  if (tl <= l && r <= tr) return t[x].s;
  int mid = l + r >> 1, res = 0;
  if (tl <= mid) res += qry(t[x].ls, l, mid, tl, tr);
  if (tr > mid) res += qry(t[x].rs, mid + 1, r, tl, tr);
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q);
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = max(0, a[i].q - k); j <= a[i].q + k; j++)
      ans += qry(rt[j], -inf, inf, a[i].x - a[i].r, a[i].x + a[i].r);
    upd(rt[a[i].q], -inf, inf, a[i].x);
  }
  printf("%d\n", ans);
  return 0;
}
