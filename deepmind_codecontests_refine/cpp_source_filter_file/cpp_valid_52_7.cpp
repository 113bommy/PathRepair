#include <bits/stdc++.h>
using namespace std;
int a[100005];
double get(int m, int n) {
  double sum = 0;
  for (int i = m; i <= n; i++) {
    sum += a[i];
  }
  return sum / (n - m + 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 1, r = n - 2;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (get(0, mid) + get(mid + 1, n - 1) >= get(0, 0) + get(1, n - 1))
        l = mid;
      else
        r = mid - 1;
    }
    double ans = get(0, l) + get(l + 1, n - 1);
    printf("%.9lf\n", ans);
  }
}
