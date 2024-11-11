#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
const long long P = 1e9 + 7;
long long arr[10000];
signed main() {
  long long x, y, z;
  while (scanf("%lld%lld%lld", &x, &y, &z) != EOF) {
    if (x == 1 && y == 1) {
      if (z == 1) {
        puts("infinity");
        continue;
      } else {
        puts("0");
        continue;
      }
    } else if (x == y) {
      if (z == y) {
        puts("2");
        continue;
      } else {
        puts("0");
        continue;
      }
    } else if (y == z) {
      puts("1");
      continue;
    } else if (x > y || y > z) {
      puts("0");
      continue;
    } else if (x == 1) {
      for (register long long i = 1; i <= 100; ++i) arr[i] = 0;
      long long tmp = z, tot = 0;
      while (tmp > 0) {
        arr[++tot] = tmp % y;
        tmp /= y;
      }
      long long sum = 0;
      for (register long long i = 1; i <= 100; ++i) sum += arr[i];
      if (sum == y || sum == 1)
        puts("1");
      else
        puts("0");
    } else {
      for (register long long i = 1; i <= 100; ++i) arr[i] = 0;
      long long tot = 0, tmp = z;
      while (tmp > 0) {
        arr[++tot] = tmp % y;
        tmp /= y;
      }
      long long sum = 0, mul = 1;
      for (register long long i = 1; i <= tot; ++i) {
        sum += mul * arr[i];
        mul *= x;
      }
      printf("%d\n", sum == y ? 1 : 0);
    }
  }
  return 0;
}
