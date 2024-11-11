#include <bits/stdc++.h>
using namespace std;
int n, a[10005], i, j, k, l;
vector<int> v;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (i = 0; i <= n; i++) {
    if (a[i] >= 0) {
      k = i;
      if (i % 2 == 1) {
        for (i = 0; i < k - 1; i++) v.push_back(a[i]);
      } else {
        for (i = 0; i < k; i++) v.push_back(a[i]);
      }
      break;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if (a[i] <= 0) break;
    v.push_back(a[i]);
  }
  if (v.empty())
    printf("%d\n", a[n - 1]);
  else
    for (i = 0; i < v.size(); i++) printf("%d ", v[i]);
  return 0;
}
