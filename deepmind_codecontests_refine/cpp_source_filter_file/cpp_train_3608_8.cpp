#include <bits/stdc++.h>
using namespace std;
int n, a;
long long sum[200010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    sum[i] = sum[i - 1] + a;
  }
  printf("%lld\n",
         max((long long)(upper_bound(sum + 1, sum + 1 + n, (sum[n] + 1) / 2) -
                         sum - 1),
             1ll));
  return 0;
}
