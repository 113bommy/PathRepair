#include <bits/stdc++.h>
using namespace std;
int A[22];
int main() {
  int k, i, r = 0x3f3f3f3f, f = 0, j;
  scanf("%d", &k);
  if (!k) {
    puts("0");
    return 0;
  }
  for (i = 0; i < 12; i++) scanf("%d", &A[i]);
  int h = 1 << 12, mask;
  for (mask = 0; mask < h; mask++) {
    f = 0;
    int m = 0;
    for (i = 1; i < 12; i++)
      if (mask & (1 << i)) f += A[i], m++;
    if (f >= k) r = min(r, m);
  }
  if (r < 0x3f3f3f3f)
    printf("%d\n", r);
  else
    puts("-1");
  return 0;
}
