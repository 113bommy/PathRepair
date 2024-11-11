#include <bits/stdc++.h>
using namespace std;
int f[2000001], t, n;
const int p = 1e9 + 7;
int main() {
  scanf("%d", &t);
  f[1] = f[2] = 0;
  f[3] = 4;
  for (int i = 4; i <= 2e6; ++i)
    f[i] = ((2ll * f[i - 2] % p + f[i - 1]) % p + 4 * (!!(n % 3))) % p;
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", f[n]);
  }
  return 0;
}
