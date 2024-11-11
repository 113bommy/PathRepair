#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
int k, c[1000];
long long int perm[1001];
long long int ans;
long long int extgcd(long long int a, long long int b, long long int &x,
                     long long int &y) {
  long long int g = a;
  x = 1;
  y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
long long int mod_inverse(long long int a, long long int m = MOD) {
  long long int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
long long int nCr(int n, int r) {
  return (((perm[n] * mod_inverse(perm[r])) % MOD) * mod_inverse(perm[n - r])) %
         MOD;
}
int main(void) {
  int i, j;
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    scanf("%d", c + i);
  }
  perm[0] = 1;
  for (i = 1; i < 1001; i++) {
    perm[i] = perm[i - 1] * i;
  }
  ans = 1;
  for (i = k - 1; i >= 1; i--) {
    int sum = 0;
    for (j = i - 1; j >= 0; j--) {
      sum += c[j];
    }
    ans = (ans * nCr(sum + c[i] - 1, c[i] - 1)) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
