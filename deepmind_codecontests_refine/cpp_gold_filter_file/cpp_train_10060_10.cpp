#include <bits/stdc++.h>
using namespace std;
const int nn = 1e5 + 8;
int Max[nn];
int a[nn];
int sum[nn];
int t[nn];
int calc(int x, int l, int r) {
  int res = 0;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (t[m] > x) {
      res = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + (a[i] > Max[i - 1]);
    Max[i] = max(Max[i - 1], a[i]);
  }
  int m = 0, x = -1, res;
  for (int i = n; i >= 1; i--) {
    int tmp = sum[i - 1] + calc(Max[i - 1], 1, m);
    if (tmp > x) {
      x = tmp;
      res = a[i];
    } else if (x == tmp)
      res = min(res, a[i]);
    while (m >= 1 and t[m] < a[i]) m--;
    t[++m] = a[i];
  }
  cout << res;
}
