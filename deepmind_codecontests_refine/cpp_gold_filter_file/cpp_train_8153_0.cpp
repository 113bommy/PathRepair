#include <bits/stdc++.h>
using namespace std;
int n, a[100004], m, k, x;
pair<int, int> ans[200000];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n + 1; ++i) {
    if (a[i] > x) {
      int l = a[i] - x;
      for (int j = 0; j < l; ++j) ans[m++].first = i;
    } else if (a[i] < x) {
      int l = x - a[i];
      for (int j = 0; j < l; ++j) ans[k++].second = i - 1;
    }
    x = a[i];
  }
  printf("%d\n", m);
  for (int i = 0; i < m; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
