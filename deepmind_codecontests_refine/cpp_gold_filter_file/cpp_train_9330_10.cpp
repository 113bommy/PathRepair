#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, mo = 1e9 + 7;
int Pow(int x, int p) {
  long long xx = x, res = 1;
  while (p) {
    if (p & 1) res = res * xx % mo;
    xx = xx * xx % mo;
    p >>= 1;
  }
  return (int)res;
}
int inv(int x) { return Pow(x, mo - 2); }
long long kt[maxn];
long long f[maxn];
int n, k, ans;
int main() {
  kt[0] = 1;
  for (int i = 1; i <= 1000000; i++) kt[i] = kt[i - 1] * i % mo;
  scanf("%d%d", &n, &k);
  if (k + 1 >= n) {
    puts("0");
    return 0;
  }
  for (int i = k + 2; i <= n; i++) {
    static long long sum = 0;
    f[i] = kt[i - 2] * (i - k - 1) % mo;
    f[i] = (f[i] + sum * kt[i - 2] % mo) % mo;
    sum = (sum + f[i] * inv(kt[i - 1]) % mo) % mo;
    if (i - k >= k + 2)
      sum = (sum - f[i - k] * inv(kt[i - k - 1]) % mo + mo) % mo;
  }
  for (int i = k + 2; i <= n; i++) {
    ans = (ans + f[i] * kt[n - 1] % mo * inv(kt[i - 1]) % mo) % mo;
  }
  printf("%d\n", ans);
  return 0;
}
