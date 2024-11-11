#include <bits/stdc++.h>
using namespace std;
int N;
int min1, max1, min2, max2, min3, max3;
int res1 = -1, res2 = -1, res3 = -1;
int main() {
  scanf("%d", &N);
  scanf("%d%d", &min1, &max1);
  scanf("%d%d", &min2, &max2);
  scanf("%d%d", &min3, &max3);
  for (auto i = min3; i != max3 + 1 - 2 * (min3 > max3);
       i += 1 - 2 * (min3 > max3)) {
    if (i + min1 + min2 == N) {
      res3 = i;
      break;
    }
  }
  if (res3 == -1) res3 = max3;
  N -= res3;
  for (auto i = min2; i != max2 + 1 - 2 * (min2 > max2);
       i += 1 - 2 * (min2 > max2)) {
    if (i + min1 == N) {
      res2 = i;
      break;
    }
  }
  if (res2 == -1) res2 = max2;
  N -= res2;
  res1 = N;
  printf("%d %d %d\n", res1, res2, res3);
  return 0;
}
