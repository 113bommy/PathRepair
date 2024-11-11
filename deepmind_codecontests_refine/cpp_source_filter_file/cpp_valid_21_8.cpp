#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, mod = 998244353;
int n, m;
map<int, int> mp;
int y[N], x[N], s[N];
long long sum[N];
long long f[N];
int main() {
  int _;
  {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &x[i], &y[i], &s[i]);
      f[i] = x[i] - y[i];
    }
    for (int i = 1; i <= n; i++) {
      int k = lower_bound(x + 1, x + n + 1, y[i]) - x;
      f[i] = (f[i] + sum[i - 1] - sum[k - 1]) % mod;
      sum[i] = (sum[i - 1] + f[i]) % mod;
    }
    long long ans = (x[n] + 1) % mod;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 1) ans = (ans + f[i]) % mod;
    }
    printf("%lld\n", ans);
  }
}
