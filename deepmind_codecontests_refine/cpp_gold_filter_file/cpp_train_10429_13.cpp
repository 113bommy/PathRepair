#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long phi[1000100];
int main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) phi[i] = i;
  for (long long i = 2; i <= n; i++)
    if (phi[i] == i) {
      for (long long j = i; j <= n; j += i) phi[j] = phi[j] * (i - 1) / i;
    }
  if (k == 1) {
    printf("3\n");
    return 0;
  }
  sort(phi + 3, phi + n + 1);
  long long res = 2;
  for (long long i = 3; i <= k + 2; i++) res += phi[i];
  printf("%lld\n", res);
  return 0;
}
