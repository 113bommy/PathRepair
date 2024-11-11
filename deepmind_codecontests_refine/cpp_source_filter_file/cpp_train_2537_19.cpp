#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3fll;
long long int getint() {
  long long int ret = 0;
  bool f = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f ^= 1;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return f ? -ret : ret;
}
using namespace std;
const int MAXN = 100;
int a[MAXN + 10], rk[MAXN + 10];
bool cmp(int i, int j) { return a[i] < a[j]; }
int main() {
  int n = getint(), w = getint(), sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += a[i] = getint();
    rk[i] = i;
  }
  sort(rk + 1, rk + n + 1, cmp);
  if (n == 1) {
    if (a[1] != w)
      printf("No\n");
    else {
      printf("Yes\n");
      for (int i = 1; i <= 2 * a[1]; ++i) printf(i == 2 * a[1] ? "1\n" : "1 ");
    }
    return 0;
  }
  if (w <= 0 || w > sum) {
    printf("No\n");
    return 0;
  }
  sort(a + 1, a + n + 1);
  if (w == 1) {
    if (a[1] > 1)
      printf("No\n");
    else {
      printf("Yes\n");
      printf("%d ", rk[1]);
      for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= 2 * a[i]; ++j) printf("%d ", rk[i]);
      printf("%d\n", rk[1]);
    }
    return 0;
  }
  printf("Yes\n");
  if (w >= a[1]) {
    int y = 0;
    for (int i = 1; i <= 2 * (a[1] - 1); ++i) printf("%d ", rk[1]);
    y = a[1] - 1;
    if (y == w - 1) printf("%d ", rk[1]);
    for (int i = 2; i <= n; ++i)
      for (int j = 1; j <= a[i]; ++j) {
        printf("%d %d ", rk[i], rk[i]);
        ++y;
        if (y == w - 1) printf("%d ", rk[1]);
      }
    printf("%d\n", rk[1]);
  } else {
    printf("%d ", rk[2]);
    for (int i = 1; i <= 2 * (a[1] - 1); ++i) printf("%d ", rk[1]);
    a[2] -= w;
    for (int i = 1; i <= 2 * w - 1; ++i) printf("%d ", rk[2]);
    printf("%d ", rk[1]);
    for (int i = 2; i <= n; ++i)
      for (int j = 1; j <= 2 * a[i]; ++j) printf("%d ", rk[i]);
    printf("%d\n", rk[1]);
  }
}
