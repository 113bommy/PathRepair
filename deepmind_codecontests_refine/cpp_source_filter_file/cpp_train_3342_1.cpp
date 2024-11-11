#include <bits/stdc++.h>
int n, m;
long long v[110], ans[3];
int max(int a, int b) { return a > b ? a : b; }
void cmax(int& a, int b) { b > a ? a = b : 1; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%lld", v + i);
  for (int k = 2; k <= m * 2; k++) {
    int l = max(1, k - m), r = k + 1 >> 1, mx = -1, mx2 = -1, t = 1;
    for (int i = 0; i < n; i++) {
      int x = v[i] % k;
      cmax(l, x < r ? x + 1 : k - x);
      if (x > mx)
        mx2 = mx, mx = x;
      else
        cmax(mx2, x);
      if (x >= r) t = !t;
    }
    cmax(l, mx2 / 2 + 1);
    ans[t] += r - l << 1 | k & 1 ^ 1;
    ans[2] += l - max(1, k - m);
    r = mx / 2 + 1;
    if (l < r && t) ans[2] += r - l, ans[1] -= r - l << 1;
  }
  printf("%lld%lld%lld%lld\n", ans[2], ans[2], ans[0], ans[1]);
}
