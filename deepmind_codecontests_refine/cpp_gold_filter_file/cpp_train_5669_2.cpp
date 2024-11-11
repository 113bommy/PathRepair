#include <bits/stdc++.h>
using namespace std;
int a[100005];
int solve(int l, int r, int ht) {
  int ans = r - l + 1, i, mn = INT_MAX;
  for (i = l; i < r + 1; i++) {
    mn = min(mn, a[i] - ht);
  }
  ht += mn;
  int _ans = mn;
  int st = 0, en = 0;
  for (i = l; i < r + 1; i++) {
    if (a[i] <= ht) continue;
    st = i;
    while (a[i + 1] > ht) i++;
    en = i;
    _ans += solve(st, en, ht);
  }
  return min(ans, _ans);
}
int main() {
  int n, i, ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  ans = solve(0, n - 1, 0);
  printf("%d\n", ans);
  return 0;
}
