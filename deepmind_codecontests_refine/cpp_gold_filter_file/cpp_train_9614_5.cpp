#include <bits/stdc++.h>
long long arr[55], cost[5], cnt[5], sum;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  for (int i = 0; i < 5; i++) scanf("%lld", &cost[i]);
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    for (int j = 4; j >= 0; j--) {
      if (cost[j] <= sum) {
        cnt[j] += sum / cost[j];
        sum -= (sum / cost[j]) * cost[j];
      }
    }
  }
  for (int i = 0; i < 5; i++) printf("%lld ", cnt[i]);
  puts("");
  printf("%lld\n", sum);
  return 0;
}
