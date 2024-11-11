#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, L = 26, MOD = 1e9 + 7, P = 727, SQ = sqrt(N),
          M = 2e5 + 10;
const long long inf = 3e18 + 10;
int tim[N], seg[N], a[N], b[N], n, m;
int Left(int p) { return 2 * p; }
int Right(int p) { return 2 * p + 1; }
void shift(int s, int e, int ind) {
  int c1 = Left(ind), c2 = Right(ind);
  if (tim[c1] < tim[ind]) tim[c1] = tim[ind], seg[c1] = seg[ind];
  if (tim[c2] < tim[ind]) {
    int len = (s + e) / 2 - s;
    tim[c2] = tim[ind], seg[c2] = seg[ind] + len;
  }
}
void add(int s, int e, int ind, int l, int r, int x, int tt) {
  if (l >= e || r <= s) return;
  if (s >= l && e <= r) {
    tim[ind] = tt;
    seg[ind] = s - l + x;
    return;
  }
  shift(s, e, ind);
  int mid = (s + e) / 2;
  add(s, mid, Left(ind), l, r, x, tt);
  add(mid, e, Right(ind), l, r, x, tt);
}
int query(int s, int e, int ind, int l, int r) {
  if (s >= r || e <= l) return 0;
  if (s >= l && e <= r && seg[ind] == 0) return b[l];
  if (s >= l && e <= r) return a[seg[ind]];
  shift(s, e, ind);
  int mid = (s + e) / 2;
  return query(s, mid, Left(ind), l, r) + query(mid, r, Right(ind), l, r);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) {
    int t, x, y, k;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d %d", &x, &y, &k);
      add(1, n + 1, 1, y, y + k, x, i);
    }
    if (t == 2) {
      scanf("%d", &x);
      printf("%d\n", query(1, n + 1, 1, x, x + 1));
    }
  }
  return 0;
}
