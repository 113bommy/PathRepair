#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int N = 1000000 + 10, maxn = 50000 + 10, inf = 0x3f3f3f3f,
          INF = 0x3f3f3f3f3f3f3f3f;
long long num[N], a[N];
long long quick(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 998244353;
    a = a * a % 998244353;
    b >>= 1;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  num[0] = 1;
  for (int i = 1; i <= n; i++)
    num[i] = (num[i - 1] * 2 % 998244353 + quick(2, i - 1)) % 998244353;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + a[i] % 998244353 * num[n - i - 1] % 998244353) % 998244353;
  }
  printf("%lld\n", ans);
  return 0;
}
