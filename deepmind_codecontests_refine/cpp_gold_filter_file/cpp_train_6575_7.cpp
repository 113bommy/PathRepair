#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[300100], sum[300100];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = n - 1; i >= 0; i--) sum[i] = sum[i + 1] + a[i];
  long long ans = sum[0];
  sort(sum + 1, sum + n);
  for (int i = 0; i < k - 1; i++) ans += sum[n - 1 - i];
  printf("%lld", ans);
  return 0;
}
