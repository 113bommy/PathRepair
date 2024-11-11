#include <bits/stdc++.h>
using namespace std;
int n, arr[105], xam, cur, res;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  xam = 10000000;
  for (int i = 1; i <= 1000; i++) {
    int cur = 0;
    for (int j = 0; j < n; j++) {
      cur += max(abs(arr[j] - i) - 1, 0);
    }
    if (cur < xam) {
      xam = cur;
      res = i;
    }
  }
  printf("%d %d\n", res, xam);
}
