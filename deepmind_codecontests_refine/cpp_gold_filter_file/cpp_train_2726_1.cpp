#include <bits/stdc++.h>
using namespace std;
long long h, w;
long long Map[1010][1010];
long long r[1010], c[1010];
long long PowMod(long long a, long long b, long long c) {
  long long result = 1;
  long long base = a % c;
  while (b) {
    if (b & 1) result = (result * base) % c;
    base = (base * base) % c;
    b >>= 1;
  }
  return result;
}
int main() {
  scanf("%lld%lld", &h, &w);
  memset(Map, -1, sizeof(Map));
  int f = 1;
  for (long long i = 1; i <= h; i++) {
    scanf("%lld", &r[i]);
    for (long long j = 1; j <= r[i]; j++) {
      Map[i][j] = 1;
    }
    Map[i][r[i] + 1] = 0;
  }
  for (long long i = 1; i <= w; i++) {
    scanf("%lld", &c[i]);
    for (long long j = 1; j <= c[i]; j++) {
      if (Map[j][i] == 0) {
        f = 0;
      }
      Map[j][i] = 1;
    }
    if (Map[c[i] + 1][i] == 1) {
      f = 0;
    }
    Map[c[i] + 1][i] = 0;
  }
  long long p = 0;
  if (f == 0) {
    printf("0\n");
    return 0;
  }
  for (long long i = 1; i <= h; i++) {
    for (long long j = 1; j <= w; j++) {
      if (Map[i][j] == -1) {
        p++;
      }
    }
  }
  long long ans = PowMod(2, p, 1000000007);
  printf("%lld\n", ans);
  return 0;
}
