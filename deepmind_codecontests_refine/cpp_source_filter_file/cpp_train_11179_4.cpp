#include <bits/stdc++.h>
using namespace std;
int i, j, n, k, ans[11111], add[11111], table[11111][22];
int search(int x) {
  int l = 1, r = n, z = n - x - ans[x];
  while (r - l > 1) {
    int ave = (l + r) / 2;
    if (ans[ave] >= z)
      l = ave;
    else
      r = ave;
  }
  if (ans[l] > z) l = r;
  return l;
}
int main() {
  cin >> n >> k;
  for (i = 1; i < n; i++) ans[i] = 1;
  for (i = 1; i <= k; i++) {
    for (j = 1; j <= n; j++) {
      int t = search(j);
      add[j] = ans[t];
      table[i][j] = t;
    }
    for (j = 1; j <= n; j++) ans[j] += add[j];
  }
  for (i = 1; i <= k; i++) {
    for (j = 1; j < n; j++) printf("%d ", table[i][j]);
    printf("%d\n", table[i][n]);
  }
  return 0;
}
