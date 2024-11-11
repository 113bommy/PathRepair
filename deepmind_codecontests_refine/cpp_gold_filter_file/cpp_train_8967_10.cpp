#include <bits/stdc++.h>
using namespace std;
long long qk(long long x, int y) {
  long long r = 1;
  for (; y; y >>= 1) {
    if (y & 1) r = r * x % 1000003;
    x = x * x % 1000003;
  }
  return r;
}
long long a[11][12];
int main() {
  for (int i = (0); i <= (10); ++i) {
    int x = 1;
    for (int j = (0); j <= (10); ++j) a[i][j] = x, x = x * i % 1000003;
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%lld", &a[i][11]);
  }
  for (int i = (0); i <= (10); ++i) {
    for (int j = (11); j >= (i); --j)
      a[i][j] = a[i][j] * qk(a[i][i], 1000003 - 2) % 1000003;
    for (int j = (i + 1); j <= (10); ++j)
      for (int k = (11); k >= (i); --k)
        a[j][k] = (a[j][k] + 1000003 - a[i][k] * a[j][i] % 1000003) % 1000003;
  }
  for (int i = (10); i >= (0); --i)
    for (int j = (i - 1); j >= (0); --j) {
      a[j][11] = (a[j][11] + 1000003 - a[j][i] * a[i][11] % 1000003) % 1000003;
      a[j][i] = 0;
    }
  for (int i = (0); i <= (1000003 - 1); ++i) {
    long long s = 0;
    for (int j = (0); j <= (10); ++j) s = (s + qk(i, j) * a[j][11]) % 1000003;
    if (!s) {
      printf("! %d\n", i);
      fflush(stdout);
      return 0;
    }
  }
  printf("! -1\n");
  fflush(stdout);
}
