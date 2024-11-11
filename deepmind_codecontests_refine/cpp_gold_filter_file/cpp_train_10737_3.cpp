#include <bits/stdc++.h>
using namespace std;
const int mn = 1e6 + 5;
int n;
int a[mn];
int l1[mn], l2[mn], r1[mn], r2[mn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      l1[i] = l1[i - 1] + 1;
      l2[i] = 0;
    } else {
      l1[i] = 0;
      l2[i] = l2[i - 1] + 1;
    }
  }
  for (int i = n; i; i--) {
    if (a[i] == 1) {
      r1[i] = r1[i + 1] + 1;
      r2[i] = 0;
    } else {
      r1[i] = 0;
      r2[i] = r2[i + 1] + 1;
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++)
    ans = max({ans, 2 * min(l1[i], r2[i + 1]), 2 * min(l2[i], r1[i + 1])});
  printf("%d\n", ans);
  return 0;
}
