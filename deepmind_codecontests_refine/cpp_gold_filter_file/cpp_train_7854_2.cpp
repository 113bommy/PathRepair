#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[5050];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second >= ans)
      ans = a[i].second;
    else
      ans = a[i].first;
  }
  printf("%d", ans);
  return 0;
}
