#include <bits/stdc++.h>
using namespace std;
int a[200000 + 5];
int n, k, rem, rk;
long long sum;
int main() {
  scanf("%d%d", &n, &k);
  rem = n;
  rk = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    long long d = 1ll * sum - 1ll * (rk - 1) * (rem - rk) * a[i];
    if (d < (long long)k)
      rem--, printf("%d\n", i);
    else
      sum += a[i] * (i - 1), rk++;
  }
  return 0;
}
