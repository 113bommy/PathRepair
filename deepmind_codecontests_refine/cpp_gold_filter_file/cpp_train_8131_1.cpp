#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
long long a[mx];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  int m = unique(a + 1, a + n + 1) - (a + 1);
  long long sum = 0;
  int t = 0;
  for (int i = 1; i <= m; i++) {
    printf("%lld\n", a[i] - sum);
    sum += a[i] - sum;
    t++;
    if (t == k) break;
  }
  while (t < k) {
    printf("0\n");
    t++;
  }
  return 0;
}
