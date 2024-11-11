#include <bits/stdc++.h>
int main() {
  int n, k, l, c, d, p, nl, np;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  int vol, slices;
  vol = k * l;
  slices = c * d;
  int i = 0;
  while (vol >= 0 && slices >= 0 && p >= 0) {
    vol -= n * nl;
    p -= n * np;
    slices -= n * 1;
    i = i + 1;
  }
  printf("%d\n", i - 1);
  return 0;
}
