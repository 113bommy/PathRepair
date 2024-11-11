#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 111;
long long t[4 * N];
int n, m, a[N], mx[N], R[N], p[N], b[N], ans;
multiset<pair<int, int> > second;
void upd(int v, int tl, int tr, int pos, int val) {
  t[v] += val;
  if (tl == tr) return;
  int tm = (tl + tr) >> 1;
  if (pos <= tm)
    upd(v + v, tl, tm, pos, val);
  else
    upd(v + v + 1, tm + 1, tr, pos, val);
}
long long get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[v];
  int tm = (tl + tr) >> 1;
  return get(v + v, tl, tm, l, min(r, tm)) +
         get(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
}
bool cmp(int x, int y) { return p[x] < p[y]; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    upd(1, 1, n, i, a[i]);
    second.insert(make_pair(-i, a[i]));
  }
  for (int i = n; i >= 1; --i) mx[i] = max(mx[i + 1], a[i]);
  for (int i = 1, l, r, md; i <= m; ++i) {
    scanf("%d", &b[i]);
    l = 1, r = n, R[i] = n + n;
    while (l <= r) {
      md = (l + r) >> 1;
      if (mx[md] >= b[i]) {
        R[i] = md;
        l = md + 1;
      } else
        r = md - 1;
    }
  }
  for (int i = 1; i <= m; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= m; ++i) a[i] = i;
  sort(a + 1, a + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    if (R[a[i]] > n) continue;
    if (get(1, 1, n, 1, R[a[i]]) >= p[a[i]]) {
      ans++;
      while (p[a[i]]) {
        pair<int, int> pr = *second.lower_bound(make_pair(-R[a[i]], -1));
        second.erase(pr);
        int val = min(p[a[i]], pr.second);
        p[a[i]] -= val;
        pr.second -= val;
        upd(1, 1, n, -pr.first, -val);
        if (pr.second) second.insert(pr);
      }
    }
  }
  printf("%d", ans);
  return 0;
}
