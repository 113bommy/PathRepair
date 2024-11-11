#include <bits/stdc++.h>
using namespace std;
int th[100080], bl[100080];
int main() {
  int i, j, n, k, mx = 0, sum, fl, fval;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &th[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &bl[i]);
  }
  j = 0;
  i = 0;
  sum = 0;
  fl = 0;
  fval = th[0];
  while (j < n) {
    while (i < k && j < n) {
      if (bl[j] == 0) sum += th[j];
      i++;
      j++;
    }
    if (i == k && j <= n) {
      if (sum > mx) mx = sum;
      fl++;
      if (bl[fl - 1] == 0) sum -= fval;
      fval = th[fl];
      i--;
    }
  }
  for (i = 0; i < n; i++) {
    if (bl[i] == 1) mx += th[i];
  }
  printf("%d", mx);
  return 0;
}
