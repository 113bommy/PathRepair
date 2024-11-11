#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
long long n, arr[N], full;
int main() {
  scanf("%lld", &n);
  for (long long a = 1; a <= n; a++) {
    scanf("%lld", &arr[a]);
    full += arr[a];
  }
  long long ans = full;
  for (long long a = n - 1; a >= 1; a--) {
    full -= arr[a + 1];
    ans = max(ans, full - ans);
  }
  printf("%lld\n", ans);
  return 0;
}
