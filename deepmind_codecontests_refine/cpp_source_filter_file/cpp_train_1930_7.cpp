#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long f[1000005];
long long h[1000005];
vector<int> vec;
map<int, int> mp;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &h[i]);
  }
  long long ans = 0;
  h[0] = 1;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i]++;
    if (i < n) {
      if (h[i] > h[i + 1]) {
        f[i + 1] += (h[i + 1] - 1) * f[i];
        f[i + 1] %= mod;
        if (h[i] > h[i - 1]) {
          f[i + 1] += (max(1LL, min(h[i + 1], h[i - 1])) - 1) * f[i - 1];
          f[i + 1] %= mod;
        }
      }
    }
    f[i] *= (h[i] - 1);
    f[i] %= mod;
    if (h[i] >= h[i - 1]) {
      f[i] += (max(1LL, h[i - 1]) - 1) * f[i - 1];
      f[i] %= mod;
    }
    ans = (ans + f[i]) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
