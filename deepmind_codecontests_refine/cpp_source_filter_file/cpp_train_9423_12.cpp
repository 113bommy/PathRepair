#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
long long d1[1 << 19], d2[1 << 19];
int h = 1 << 18;
long long sum1(int i, int j) {
  long long r = 0;
  for (i += h, j += h; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
    if (i & 1) r += d1[i];
    if (~j & 1) r += d1[j];
  }
  return r;
}
long long sum2(int i, int j) {
  long long r = 0;
  for (i += h, j += h; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
    if (i & 1) r += d2[i];
    if (~j & 1) r += d2[j];
  }
  return r;
}
void upd1(int i, long long x) {
  for (i += h; i > 0; d1[i] += x, i >>= 1)
    ;
}
void upd2(int i, long long x) {
  for (i += h; i > 0; d2[i] += x, i >>= 1)
    ;
}
int v1[200100], v2[200100];
int main() {
  int n, a, b, k, q, i;
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  for (; q--;) {
    scanf("%d", &i);
    if (i == 1) {
      int x;
      scanf("%d%d", &i, &x);
      i--;
      upd1(i, min(a - v1[i], x));
      upd2(i, min(b - v2[i], x));
      v1[i] += min(a - v1[i], x);
      v2[i] += min(a - v2[i], x);
    } else {
      scanf("%d", &i);
      i--;
      printf("%lld\n", sum2(0, i - 1) + sum1(i + k, n - 1));
    }
  }
  return 0;
}
