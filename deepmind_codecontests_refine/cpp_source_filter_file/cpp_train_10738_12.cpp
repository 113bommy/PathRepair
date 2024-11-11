#include <bits/stdc++.h>
using namespace std;
int a[200005];
int book[200005];
int n, z;
int solve(int m) {
  for (int i = 0; n - m + i < n; i++) {
    if (a[n - m + i] - a[i] < z) {
      return 0;
    }
  }
  return 1;
}
int main() {
  scanf("%d %d", &n, &z);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (solve(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d", ans);
  return 0;
}
