#include <bits/stdc++.h>
int n, k, q, l, r, val[200005], bit[200005];
int sum(int m) {
  int s = 0;
  for (int i = m; i; i -= i & -i) s += bit[i];
  return s;
}
int main() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    val[l]++;
    val[r + 1]--;
  }
  for (int i = 0; i <= 200000; i++) val[i] += val[i - 1];
  for (int i = 1; i <= 200000; i++) {
    val[i] = val[i] >= k;
    for (int j = i; j <= n; j += j & -j) bit[j] += val[i];
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", sum(r) - sum(l - 1));
  }
}
