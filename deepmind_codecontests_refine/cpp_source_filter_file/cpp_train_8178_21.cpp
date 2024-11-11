#include <bits/stdc++.h>
using namespace std;
long long sum[112345];
long long v[112345];
int main() {
  long long n;
  scanf("%lld", &n);
  sum[0] = 0LL;
  long long h1 = 1, h2 = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    h1 = lower_bound(v, v + i, v[i] - 90) - v;
    h2 = lower_bound(v, v + i, v[i] - 1440) - v;
    long long v1 = 50ll - (sum[i - 1] - sum[h1 - 1]);
    long long v2 = 120ll - (sum[i - 1] - sum[h2 - 1]);
    sum[i] = min(20ll, min(v1, v2)) + sum[i - 1];
    printf("%lld\n", sum[i] - sum[i - 1]);
  }
  return 0;
}
