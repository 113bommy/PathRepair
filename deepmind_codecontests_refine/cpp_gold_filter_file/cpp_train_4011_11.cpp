#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXN = 1e6 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
const long long int LOG = 22;
long long int a, b, ans = 1, dp[2][MAXN];
int main() {
  scanf("%lld%lld", &a, &b);
  if (a == b) return !printf("%lld\n", (1LL << __builtin_popcountll(a)) - 2);
  if ((a - b) & 1 || (b > a) || (a - b) >> 1 & b) return !printf("%lld\n", 0LL);
  printf("%lld\n", 1LL << __builtin_popcountll(b));
  return 0;
}
