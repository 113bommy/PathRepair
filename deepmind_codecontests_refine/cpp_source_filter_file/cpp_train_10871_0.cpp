#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 2];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ans = 1e9, start, d;
  for (int i = 0; i <= a[n - 1] - a[1]; i++) {
    int minm = 90000, maxm = -90000;
    for (int j = 0; j < n; j++) {
      int t = i * j - a[j];
      if (t > maxm) maxm = t;
      if (t < minm) minm = t;
    }
    int mid = (maxm + minm) / 2;
    int cha = max(maxm - mid, mid - minm);
    if (cha < ans) {
      ans = cha;
      start = -mid;
      d = i;
    }
  }
  printf("%d\n%d %d", ans, start, d);
  return 0;
}
