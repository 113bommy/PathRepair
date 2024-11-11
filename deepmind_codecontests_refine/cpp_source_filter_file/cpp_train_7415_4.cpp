#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
const long long mod = 998244353;
int a[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  long long ans = 0;
  for (int i = (n - k + 1); i < (n + 1); ++i) ans += i;
  printf("%lld ", ans % mod);
  int cnt = 0, last;
  ans = 1;
  for (int i = (0); i < (n); ++i) {
    if (a[i] > n - k) {
      ++cnt;
      if (cnt > 1) {
        ans = ans * (i - last) % mod;
      }
      last = i;
    }
  }
  printf("%lld", ans);
}
