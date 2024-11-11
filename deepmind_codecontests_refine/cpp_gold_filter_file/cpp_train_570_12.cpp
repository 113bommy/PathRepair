#include <bits/stdc++.h>
using namespace std;
int q[500005];
int qwe(int l, int r) {
  int len = r - l + 1;
  if (len < 3) return 0;
  int mid = (l + r) / 2;
  for (int i = l + 1; i <= mid; i++) q[i] = q[l];
  for (int i = mid + 1; i < r; i++) q[i] = q[r];
  return (len - 1) / 2;
}
int main() {
  int n, i, j, k;
  while (~scanf("%d", &n)) {
    int ans = 0;
    for (i = 1; i <= n; i++) scanf("%d", &q[i]);
    k = 1;
    for (j = 1; j < n; j++) {
      if (q[j] == q[j + 1]) {
        ans = max(ans, qwe(k, j));
        k = j + 1;
      }
    }
    ans = max(ans, qwe(k, n));
    printf("%d\n", ans);
    for (i = 1; i <= n; i++) printf("%d ", q[i]);
    puts("");
  }
  return 0;
}
