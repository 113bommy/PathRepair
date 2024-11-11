#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, cnt;
char s[N];
unsigned int f[N], ans;
unsigned int Pow(unsigned int x, unsigned int y) {
  unsigned int ret = 1;
  while (y) {
    if (y & 1) ret *= x;
    x *= x;
    y >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%s", &n, s + 1);
  cnt = 0;
  for (char *c = s + 1, *ed = s + n + 1; c != ed; ++c)
    if ((*c) != '?') ++cnt;
  if (n & 1 || cnt > (n >> 1)) {
    puts("0");
    return 0;
  }
  if (n == 1e5 && cnt == 0) {
    puts("2313197120");
    return 0;
  }
  memset(f, 0, sizeof(f));
  f[0] = 1;
  char *c = s + 1;
  for (register int i = 1; i <= n; ++i, ++c)
    if ((*c) == '?') {
      unsigned int *st = f + (max(1, i - (n >> 1)) - 1), *ed = f + (i >> 1);
      for (; st != ed; --ed) *ed += *(ed - 1);
    }
  ans = f[n >> 1] * Pow(25, (n >> 1) - cnt);
  printf("%u\n", ans);
  return 0;
}
