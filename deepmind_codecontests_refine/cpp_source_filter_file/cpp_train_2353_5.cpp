#include <bits/stdc++.h>
using namespace std;
int a[200010], sum[200010];
int main() {
  int n, k, q, l, r, sum1 = 0, sum2 = 0;
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    a[l]++, a[r + 1]--;
  }
  for (int i = 1; i <= k; i++) {
    sum1 += a[i];
    if (sum1 >= k) sum2++;
    sum[i] = sum2;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", sum[r] - sum[l - 1]);
  }
  return 0;
}
