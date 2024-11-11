#include <bits/stdc++.h>
using namespace std;
int a[100005];
int fi(int l, int r, int n) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == n) return 1;
    if (a[mid] < n) l = mid + 1;
    if (a[mid] > n) r = mid - 1;
  }
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, ans = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == x) ans = 1;
    }
    if (ans == 1) {
      printf("1\n");
      continue;
    }
    sort(a, a + n);
    long long int max = a[n - 1] * 2;
    if (x % a[n - 1] == 0)
      ans = x / a[n - 1];
    else if (x <= max) {
      ans = 2;
    } else {
      ans = x / max * 2 - 2;
      x = x % max + max;
      if (a[n - 1] + max >= x)
        ans += 3;
      else
        ans += 4;
    }
    printf("%d\n", ans);
  }
  return 0;
}
