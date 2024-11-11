#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 100;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
int k[N];
long long q_pow(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int w;
  cin >> w;
  while (w--) {
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++) scanf("%d", k + i);
    sort(k + 1, k + 1 + n, greater<int>());
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
      if (!ans1 && !ans2) {
        ans1 = (ans1 + q_pow(p, k[i], mod1)) % mod1;
        ans2 = (ans2 + q_pow(p, k[i], mod2)) % mod2;
      } else {
        ans1 = (ans1 - q_pow(p, k[i], mod1) + mod1) % mod1;
        ans2 = (ans2 - q_pow(p, k[i], mod2) + mod2) % mod2;
      }
    }
    printf("%lld\n", ans1);
  }
  return 0;
}
