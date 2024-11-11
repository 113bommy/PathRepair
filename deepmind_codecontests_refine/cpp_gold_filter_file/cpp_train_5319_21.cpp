#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1005;
int a[maxn], b[maxn];
bool check(double k) {
  double lft = k;
  for (int i = 1; i < n; i++) {
    lft -= (lft + m) / a[i];
    if (lft < 0) return 0;
    lft -= (lft + m) / b[i + 1];
    if (lft < 0) return 0;
  }
  lft -= (lft + m) / a[n];
  if (lft < 0) return 0;
  lft -= (lft + m) / b[1];
  if (lft < 0) return 0;
  return lft >= 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
  }
  double l = 1.0, r = 1e9 + 5, ans;
  for (int i = 1; i <= 100; i++) {
    double mid = (l + r) / 2.0;
    if (check(mid)) {
      r = mid;
      ans = mid;
    } else
      l = mid;
  }
  if (!check(r))
    puts("-1");
  else
    printf("%.10f\n", r);
  return 0;
}
