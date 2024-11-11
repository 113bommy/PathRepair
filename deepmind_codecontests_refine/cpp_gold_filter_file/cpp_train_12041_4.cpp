#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXN = 1e5 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int n;
int main() {
  scanf("%lld", &n);
  if (n <= 5) {
    printf("-1\n");
    for (long long int i = 2; i <= n; i++) printf("%lld %lld\n", i, i - 1);
    return 0;
  }
  for (long long int i = 3; i <= n; i++) {
    printf("%lld %lld\n", 2 - (i & 1), i);
  }
  printf("%lld %lld\n", 1LL, 2LL);
  for (long long int i = 2; i <= n; i++) {
    printf("%lld %lld\n", 1LL, i);
  }
  return 0;
}
