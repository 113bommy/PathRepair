#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[10010];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  long long sum = 0;
  for (int i = 1; i <= k; i++) sum += a[i];
  printf("%lld\n", sum);
  return 0;
}
