#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int f[N], c[N];
int n, k, a;
int ans, l, r;
int m;
bool check(int x) {
  memset(f, 0, sizeof f);
  int cnt = 0;
  f[++cnt] = 0;
  for (int i(1); i <= (x); ++i) f[++cnt] = c[i];
  f[++cnt] = n + 1;
  sort(f + 1, f + cnt + 1);
  int now = 0;
  for (int i(1); i <= (cnt - 1); ++i) now += (f[i + 1] - f[i]) / (a + 1);
  return now >= k;
}
int main() {
  scanf("%d%d%d", &n, &k, &a);
  scanf("%d", &m);
  for (int i(1); i <= (m); ++i) scanf("%d", c + i);
  if (check(m)) return 0 * puts("-1");
  l = 1, r = m;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid;
  }
  if (check(r))
    ans = l;
  else
    ans = r;
  printf("%d\n", ans);
  return 0;
}
