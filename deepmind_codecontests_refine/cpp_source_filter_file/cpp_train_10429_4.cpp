#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long mu[N + 5];
long long a[N + 5];
int main() {
  long long i, j, n, k;
  scanf("%lld %lld", &n, &k);
  if (k == 1) {
    printf("3\n");
    return 0;
  }
  k += 2;
  mu[1] = 1;
  for (i = 1; i < N; i++) {
    for (j = 2 * i; j < N; j += i) mu[j] -= mu[i];
  }
  for (i = 1; i < N; i++) {
    for (j = i; j < N; j += i) a[j] += i * mu[j / i];
  }
  sort(a + 1, a + n + 1);
  long long ans = 0;
  for (i = 1; i <= k; i++) ans += a[i];
  printf("%lld\n", ans);
  return 0;
}
