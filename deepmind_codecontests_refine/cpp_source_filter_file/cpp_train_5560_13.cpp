#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7;
const long long mod = 1000000007;
long long n;
long long a[N];
long long cntre1;
long long cntre2;
long long f[3000][3000];
long long check[N];
long long gt[N];
int main() {
  scanf("%lld", &n);
  gt[0] = 1;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] != -1) {
      check[a[i]] = true;
    }
    gt[i] = (gt[i - 1] * i) % mod;
  }
  for (long long i = 1; i <= n; i++) {
    if (check[i] == false && a[i] == -1) {
      cntre1 += 1;
    } else if (a[i] == -1) {
      cntre2 += 1;
    }
  }
  for (long long i = 0; i <= 3000; i++) {
    f[i][0] = gt[i];
  }
  for (long long i = 0; i <= 3000; i++) {
    f[i][1] = (i * gt[i]) % mod;
  }
  for (long long j = 2; j <= 300; j++) {
    for (long long i = 0; i <= 3000; i++) {
      f[i][j] =
          (((i * f[i][j - 1]) % mod) + ((j - 1) * f[i + 1][j - 2]) % mod) % mod;
    }
  }
  printf("%lld", f[cntre2][cntre1] % mod);
}
