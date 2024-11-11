#include <bits/stdc++.h>
using namespace std;
int n, s0, s1, a[100010];
bool check(int k) {
  int l = a[n] - k, r = a[n] + k;
  for (int i = n - 1; i >= 1; i--) {
    if (l <= a[i] && a[i] <= r) l = a[i] - k, r = a[i] + k;
    int l0 = a[i] - k, r0 = a[i] + k;
    l = max(l, l0);
    r = min(r, r0);
    if (l > r) return false;
  }
  if ((l <= s0 && s0 <= r) || (l <= s1 && s1 <= r)) return true;
  return false;
}
int main() {
  scanf("%d %d %d", &n, &s1, &s0);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = abs(s0 - s1), r = 1e9, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d", ans);
}
