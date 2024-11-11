#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100100];
int i, n, ans, d;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + 1 + n);
  d = -9999999999;
  ans = 0;
  for (i = 1; i <= n; i++) {
    if (a[i].first - a[i].second > d) {
      ans++;
      d = a[i].first;
    } else if (i == n || a[i].first + a[i].second < a[i + 1].first) {
      ans++;
      d = a[i].first + a[i].second;
    } else
      d = a[i].first;
  }
  printf("%d\n", ans);
  return 0;
}
