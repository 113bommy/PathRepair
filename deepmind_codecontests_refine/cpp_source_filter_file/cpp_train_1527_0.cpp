#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y, t, p;
} p[10005], c;
int ans[10005], n;
bool cmp1(P a, P b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
bool cmp2(P a, P b) {
  return 1LL * (a.x - c.x) * (b.y - c.y) - 1LL * (a.y - c.y) * (b.x - c.x) < 0;
}
void solve(int l, int r) {
  int t = min_element(p + l, p + r + 1, cmp1) - p;
  swap(p[l], p[t]);
  c = p[l];
  sort(p + l + 1, p + r + 1, cmp2);
  int cnt0 = 0, cnt1 = 0, K = r;
  while (c.t == p[K].t || cnt0 != cnt1) {
    if (c.t == p[K].t)
      cnt0++;
    else
      cnt1++;
    K--;
  }
  if (c.t)
    ans[p[K].p] = c.p;
  else
    ans[c.p] = p[K].p;
  if (l + 1 < K) solve(l + 1, K - 1);
  if (K < r) solve(K + 1, r);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n * 2); i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
    p[i].t = (i <= n);
    p[i].p = (i <= n ? i : i - n);
  }
  solve(1, n * 2);
  for (int i = (1); i <= (n); i++) printf("%d\n", ans[i]);
  return 0;
}
