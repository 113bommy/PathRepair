#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, t, s, res;
int main() {
  scanf("%d", &n);
  k = 4 - n % 2;
  s = (n - k) / 2;
  if (k == 3)
    res = 2;
  else
    res = 4;
  res += s * (s + k);
  printf("%d\n", res);
  if (k == 3) {
    printf("3 1 2 3\n");
    printf("3 1 2 3\n");
  } else {
    printf("3 1 2 3\n");
    printf("3 1 2 4\n");
    printf("3 1 4 3\n");
    printf("3 1 4 3\n");
  }
  for (i = k + 1; i <= n; i += 2) {
    printf("3 %d %d %d\n", i, i + 1, 1);
    printf("3 %d %d %d\n", i, i + 1, i - 1);
    for (j = 1; j <= i - 2; j++) {
      t = j + 1;
      if (t == i) t = 1;
      printf("4 %d %d %d %d\n", i, j, i + 1, t);
    }
  }
}
