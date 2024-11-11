#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int n, h, c1, c2, mv, l;
int best = 1 << 29;
int b[MAXN], ans[MAXN];
pair<int, int> a[MAXN];
int q[MAXN];
void solve() {
  int mval, Mval;
  mval = 1 << 29;
  Mval = -1;
  if (c2)
    mval = min(mval, mv + q[0] + h),
    Mval = max(Mval, (!c1 ? mv : a[n - 1].first) + q[c2 - 1] + h);
  if (c1)
    mval = min(mval, mv + a[l].first),
    Mval = max(Mval, a[n - 1].first + (c1 == 1 ? mv : a[n - 2].first));
  if (c2 > 1)
    mval = min(mval, q[0] + q[1]), Mval = max(Mval, q[c2 - 1] + q[c2 - 2]);
  if (Mval != -1 && best > Mval - mval) {
    best = Mval - mval;
    for (int i = 0; i < n; i++) ans[a[i].second] = b[i];
  }
}
int main() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) scanf("%d", &a[i].first), a[i].second = i;
  sort(a, a + n);
  l = 1;
  c1 = n - 1;
  c2 = 0;
  mv = a[0].first;
  solve();
  for (int i = 1; i < n; i++) {
    b[i] = 1;
    q[c2++] = a[i].second;
    c1--;
    l++;
    solve();
  }
  printf("%d\n", best);
  for (int i = 0; i < n; i++) printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
  return 0;
}
