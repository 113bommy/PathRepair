#include <bits/stdc++.h>
using namespace std;
const int N = 10004;
long long c, p[N], s[N], a[N], b[N], *p1, *p2, ans;
int n;
void solve() {
  if (n == 1) {
    ans = min(p[1], s[1]);
    return;
  }
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  a[0] = p[1];
  a[1] = s[1];
  p1 = a;
  p2 = b;
  int sz = sizeof(a);
  for (int i = 2; i <= n; ++i) {
    p2[0] = p1[0] + p[i];
    p2[i] = p1[i - 1] + s[i];
    for (int j = 1; j < i; ++j)
      p2[j] = min(p1[j - 1] + s[i], p1[j] + p[i] + j * c);
    swap(p1, p2);
    memset(p2, 0, sz);
  }
  ans = 9e18;
  for (int i = 1; i <= n; ++i) ans = min(ans, p1[i]);
}
int main() {
  scanf("%d%I64d", &n, &c);
  for (int i = 1; i <= n; ++i) scanf("%I64d", p + i);
  for (int i = 1; i <= n; ++i) scanf("%I64d", s + i);
  solve();
  printf("%I64d\n", ans);
  return 0;
}
