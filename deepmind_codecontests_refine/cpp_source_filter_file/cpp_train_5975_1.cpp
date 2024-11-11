#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, sum, cnt;
pair<int, int> ans[100005];
pair<int, int> a[100005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].first), a[i].second = i;
  sort(a, a + n);
  for (int i = 0; i < n / 3; i++) {
    ans[a[i].second] = {i, a[i].first - i};
  }
  for (int i = n / 3; i < n * 2 / 3; i++) {
    ans[a[i].second] = {a[i].first - i, i};
  }
  for (int i = n * 2 / 3; i < n; i++) {
    ans[a[i].second] = {a[i].first - n + i, n - i};
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) printf("%d ", ans[i].first);
  printf("\n");
  for (int i = 0; i < n; i++) printf("%d ", ans[i].second);
  printf("\n");
  return 0;
}
