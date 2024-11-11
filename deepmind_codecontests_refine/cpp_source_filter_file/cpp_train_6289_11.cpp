#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int re[100009];
int p[100009];
int n, m, a;
int ok(int c) {
  int t = a;
  for (int i = 1; i <= c; i++) {
    if (re[c - i + 1] < p[i]) t -= (p[i] - re[c - i + 1]);
  }
  return t >= 0;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &a);
  for (int i = 1; i <= n; i++) scanf("%d", &re[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
  sort(p + 1, p + m + 1);
  sort(re + 1, re + n + 1);
  for (int i = 1; i <= n / 2; i++) swap(re[i], re[n - i + 1]);
  int l = 0, r = min(n, m);
  int ans = 0;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (ok(m))
      l = m + 1, ans = m;
    else
      r = m - 1;
  }
  long long t = 0;
  for (int i = 1; i <= ans; i++) t += p[i];
  cout << ans << " " << max(0ll, t - a) << endl;
  return 0;
}
