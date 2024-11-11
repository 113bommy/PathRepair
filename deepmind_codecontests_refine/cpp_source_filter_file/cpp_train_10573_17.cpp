#include <bits/stdc++.h>
using namespace std;
int k2, k3, k5, k6;
int main() {
  scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
  int sum = 0;
  int least_256 = k2;
  if (k5 < least_256) least_256 = k5;
  if (k6 < least_256) least_256 = k5;
  k2 -= least_256;
  sum = least_256 * 256;
  int least_32 = k3;
  if (k2 < least_32) least_32 = k2;
  sum += least_32 * 32;
  printf("%d\n", sum);
  return 0;
}
