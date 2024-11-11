#include <bits/stdc++.h>
using namespace std;
long long ans, tot, n;
long long a[105];
void update(long long d) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) sum += (a[i] - 1) / d + 1;
  if (sum * d <= tot) ans = max(ans, d);
}
int main() {
  long long k;
  scanf("%lld %lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    tot += a[i];
  }
  tot += k;
  for (long long i = 1; i * i <= tot - k; i++) {
    update(i);
    update(tot / i);
  }
  printf("%lld\n", ans);
  return 0;
}
