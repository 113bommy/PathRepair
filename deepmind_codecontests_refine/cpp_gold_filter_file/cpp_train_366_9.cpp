#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[100010];
long long b[100010];
long long BZ[100010][40];
long long Min[100010][40];
long long Sum[100010][40];
int main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 0; i < n; ++i) scanf("%lld", &BZ[i][0]);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &Min[i][0]);
    Sum[i][0] = Min[i][0];
  }
  for (long long i = 1; i < 40; ++i) {
    for (long long j = 0; j < n; ++j) {
      BZ[j][i] = BZ[BZ[j][i - 1]][i - 1];
      Min[j][i] = min(Min[j][i - 1], Min[BZ[j][i - 1]][i - 1]);
      Sum[j][i] = Sum[j][i - 1] + Sum[BZ[j][i - 1]][i - 1];
    }
  }
  for (long long i = 0; i < n; ++i) {
    long long x = 0, y = 2147483647;
    long long d = i;
    long long kk = k;
    for (long long j = 39; j >= 0; --j)
      if (kk >= (1ll << j)) {
        kk -= 1ll << j;
        x += Sum[d][j];
        y = min(y, Min[d][j]);
        d = BZ[d][j];
      }
    printf("%lld %lld\n", x, y);
  }
  return 0;
}
