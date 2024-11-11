#include <bits/stdc++.h>
using namespace std;
vector<int> c[101];
int n, k, a[105] = {}, ans = 0, res = 999;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n <= k) {
    printf("0");
    return 0;
  }
  for (int j = 0; j < k; ++j) {
    for (int i = j; i < n; i += k) c[j].push_back(a[i]);
  }
  for (int i = 0; i < k; ++i) {
    sort(c[i].begin(), c[i].end());
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < c[i].size(); ++j)
      if (c[i][j - 1] != c[i][j]) {
        int temp = c[i].size() - j;
        ans += min(j, temp);
      }
  }
  printf("%d", ans);
  return 0;
}
