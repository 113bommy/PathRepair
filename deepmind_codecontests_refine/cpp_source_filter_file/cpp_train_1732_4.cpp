#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int oo = ~0u >> 2, mo = (int)1e9 + 7;
const int mn = 1100;
int a[mn], b[mn];
int n, Ans(oo), st;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  while (n & !a[n]) --n;
  for (int posi = 1; posi <= n; ++posi) {
    for (int i = 1; i <= n; ++i) b[i] = a[i] - (i >= posi && a[i]);
    int Cut = 0, Build = 0;
    for (int i = 1; i <= n; ++i) Cut += max(0, b[i] - b[i - 1]), Build += b[i];
    int Now = 2 * Cut + 3 * Build - posi;
    if (Now < Ans) Ans = Now, st = posi;
  }
  for (int i = st; i <= n; ++i) a[i] -= !!a[i];
  for (int i = 1; i <= n; ++i) {
    while (a[i]) {
      int j = 0;
      while (a[i + j]) printf("AR"), --a[i + (j++)];
      printf("A");
      while (j--) printf("L");
      printf("A");
    }
    printf("AR");
  }
  printf("A");
  for (int i = st; i <= n; ++i) printf("L");
  printf("A\n");
}
