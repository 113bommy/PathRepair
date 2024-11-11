#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long ksm(long long x, int k) {
  long long sum = 1;
  while (k) {
    if (k & 1) sum = sum * x % mod;
    x = x * x % mod;
    k >>= 1;
  }
  return sum;
}
void solve() {
  int n, k;
  long long ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 33; i >= 0; i--) {
    if ((1ll << i) <= k) {
      k -= (1 << i);
      ans = (ans + ksm(n, i)) % mod;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
