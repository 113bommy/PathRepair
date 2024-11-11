#include <bits/stdc++.h>
using namespace std;
long long f[21000], f2[21000], viz[21000], viz2[21000], solf[21000];
int n;
long long sol;
const long long mod = 1e9 + 7;
int main() {
  int i, x, j;
  scanf("%d", &n);
  i = 0;
  f[10000] = viz[10000] = solf[10000] = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    memset(f2, 0, sizeof(f2));
    memset(viz2, 0, sizeof(viz2));
    for (j = -10000 + x; j <= 10000 - x; j++) {
      f2[j + x + 10000] += f[j + 10000];
      f2[j - x + 10000] += f[j + 10000];
    }
    for (j = -10000; j <= 10000; j++) f2[j] %= mod;
    memcpy(f, f2, sizeof(f));
    memcpy(viz, viz2, sizeof(viz));
    sol = sol + f2[10000];
    sol %= mod;
    f[10000]++;
  }
  printf("%d\n", (int)sol);
  return 0;
}
