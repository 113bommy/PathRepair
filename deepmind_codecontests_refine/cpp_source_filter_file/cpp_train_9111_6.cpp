#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6, M = 2e6;
int a[maxn], b[maxn], ans[maxn];
int la, i, j, e, bl, n, x;
int main() {
  b[0] = b[1] = 1;
  for (i = 2; i <= M; i++) {
    if (b[i]) continue;
    long long p = (long long)i * i;
    while (p <= M) {
      b[p] = 1;
      p += i;
    }
  }
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) x++;
  }
  if (n == 1) {
    printf("1\n%d", a[1]);
    return 0;
  }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      if (b[a[i] + a[j]]) continue;
      ans[++la] = a[i];
      ans[++la] = a[j];
      goto pn;
    }
pn:
  if (x) {
    for (i = 1; i <= n; i++) {
      if (a[i] == 1) continue;
      if (b[a[i] + 1]) continue;
      bl = a[i];
    }
    if (bl) {
      printf("%d\n", x + 1);
      printf("%d", bl);
      for (i = 1; i <= x; i++) printf(" %d", 1);
    } else if (x > 1) {
      printf("%d\n", x);
      for (i = 1; i <= x; i++) printf("%d%c", 1, i < x ? ' ' : '\n');
    } else if (bl) {
      printf("2\n");
      printf("%d %d\n", ans[1], ans[2]);
    } else
      printf("1\n%d", a[1]);
  } else {
    if (la) {
      printf("%d\n", la);
      printf("%d %d", ans[1], ans[2]);
    } else {
      printf("1\n");
      printf("%d", a[1]);
    }
  }
  return 0;
}
