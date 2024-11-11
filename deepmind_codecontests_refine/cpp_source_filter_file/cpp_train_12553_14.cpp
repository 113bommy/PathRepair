#include <bits/stdc++.h>
const int N = 100005, mu = 1e9 + 7;
using std::stack;
stack<int> t[N << 2];
int dp[N], n, h, w, st, ans;
void reduce(int &x) { x += x >> 31 & mu; }
struct note {
  int h, l, r, x;
} a[N];
bool cmp(note x, note y) { return x.h < y.h; }
void modify(int k, int L, int R, int l, int r, int id) {
  if (L == l && R == r) {
    t[k].push(id);
    return;
  }
  int mid = (L + R) >> 1;
  if (r <= mid)
    modify(k << 1, L, mid, l, r, id);
  else if (l > mid)
    modify(k << 1 | 1, mid + 1, R, l, r, id);
  else
    modify(k << 1, L, mid, l, mid, id),
        modify(k << 1 | 1, mid + 1, R, mid + 1, r, id);
}
void query(int k, int L, int R, int x) {
  int tt;
  while (t[k].size()) {
    tt = t[k].top();
    if (a[tt].h + a[tt].x >= st) break;
    t[k].pop();
  }
  if (t[k].size() && (ans == -1 || a[tt].h > a[ans].h)) ans = tt;
  if (L == R) return;
  int mid = (L + R) >> 1;
  if (x <= mid)
    query(k << 1, L, mid, x);
  else
    query(k << 1 | 1, mid + 1, R, x);
}
int query(int x) {
  ans = -1;
  query(1, 1, w, x);
  if (ans != -1) return dp[ans];
  return 1;
}
int main() {
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a[i].h, &a[i].l, &a[i].r, &a[i].x);
  }
  std::sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    st = a[i].x;
    if (a[i].l == 1)
      dp[i] = query(a[i].r + 1) * 2;
    else if (a[i].r == w)
      dp[i] = query(a[i].l - 1) * 2;
    else
      dp[i] = query(a[i].l - 1) + query(a[i].r + 1);
    reduce(dp[i] -= mu);
    modify(1, 1, w, a[i].l, a[i].r, i);
  }
  int tot = 0;
  st = h + 1;
  for (int i = 1; i <= w; i++) reduce(tot += query(i) - mu);
  printf("%d\n", tot);
}
