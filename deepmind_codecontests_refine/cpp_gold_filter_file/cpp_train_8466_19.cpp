#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], b[N], c, n;
int check(long long M) {
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    if (ret > c) return c + 1;
    if (a[i] >= b[i] && M > c) return c + 1;
    ret = ret + (M / b[i]) * a[i] + (M % b[i]) * a[i] / b[i] + 1;
  }
  return (int)ret;
}
int main(void) {
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
  long long L = 1, R = c * 1LL * (*max_element(b, b + n)), M, ANSL = 1,
            ANSR = -1;
  while (L <= R) {
    M = (L + R) / 2;
    int r = check(M);
    if (r > c)
      R = M - 1;
    else if (r <= c) {
      ANSR = M;
      L = M + 1;
    }
  }
  L = 1, R = c * 1LL * (*max_element(b, b + n));
  while (L <= R) {
    M = (L + R) / 2;
    int r = check(M);
    if (r >= c) {
      R = M - 1;
      ANSL = M;
    } else
      L = M + 1;
  }
  if (check(ANSL) != c)
    puts("0");
  else
    printf("%I64d\n", ANSR - ANSL + 1);
  return 0;
}
