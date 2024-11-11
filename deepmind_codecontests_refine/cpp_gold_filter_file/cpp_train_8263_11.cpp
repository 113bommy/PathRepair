#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp1[1000010], ans;
int n, m, t[1000010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    if (t[i] == 2) m++;
  }
  dp1[1] = dp1[0] = 1;
  for (int i = 2; i <= n - m; i++)
    dp1[i] = (dp1[i - 1] + (long long)(i - 1) * dp1[i - 2] % mod) % mod;
  ans = dp1[n - m];
  for (int i = n - m + 1; i <= n; i++) ans = (long long)ans * i % mod;
  printf("%lld\n", ans);
}
