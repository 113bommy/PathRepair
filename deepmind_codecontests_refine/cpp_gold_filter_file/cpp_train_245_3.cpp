#include <bits/stdc++.h>
const int mo = 1000000009;
using namespace std;
int n, w, b;
long long fac[8010];
long long mul(long long a, int b) {
  long long ans = 1, w = a % mo;
  while (b) {
    if (b & 1) ans = (ans * w) % mo;
    w = (w * w) % mo;
    b /= 2;
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &w, &b);
  fac[0] = 1;
  for (int i = 1; i <= w + b; ++i) fac[i] = (fac[i - 1] * i) % mo;
  long long ans = (fac[w] * fac[b]) % mo;
  ans = (ans * (w - 1)) % mo;
  ans = (ans * fac[w + b - 3]) % mo;
  ans = (ans * mul(fac[n - 3], mo - 2)) % mo;
  ans = (ans * mul(fac[w + b - n], mo - 2)) % mo;
  printf("%lld", ans);
  return 0;
}
