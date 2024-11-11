#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1000000007;
int n, a[N], one, two;
long long f[N], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1)
      one++;
    else
      two++;
  }
  f[0] = f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= one; i++) f[i] = (f[i - 1] + (i - 1) * f[i - 2]) % mod;
  ans = 1;
  for (int i = n, j = 1; j <= two; j++, i--) ans = ans * i % mod;
  printf("%I64d\n", ans * f[one] % mod);
  return 0;
}
