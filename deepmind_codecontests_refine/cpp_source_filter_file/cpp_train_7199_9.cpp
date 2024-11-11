#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int a[200005], b[200005];
int pos[200005];
int main() {
  int n, i, j, k, ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    pos[b[i]] = i;
  }
  if (pos[1]) {
    i = 1;
    while (pos[i] == (pos[1] + i - 1)) i++;
    if (pos[i - 1] == n) {
      k = i;
      while (pos[k] <= k - i) k++;
      if (k >= n) {
        printf("%d\n", n - i + 1);
        return 0;
      }
    }
  }
  ans = 0;
  for (i = 1; i <= n; i++) {
    ans = max(ans, pos[i] + n - i + 1);
  }
  printf("%d\n", ans);
  return 0;
}
