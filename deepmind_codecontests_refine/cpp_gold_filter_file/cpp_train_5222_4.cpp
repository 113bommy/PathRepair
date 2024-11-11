#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, m;
  int l[55], r[50], x[50], res[55];
  scanf("%d%d%d", &n, &h, &m);
  fill(res, res + 53, h);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &l[i], &r[i], &x[i]);
    for (int j = l[i]; j <= r[i]; j++) {
      if (x[i] < res[j]) {
        res[j] = x[i];
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += res[i] * res[i];
  }
  printf("%I64d", ans);
}
