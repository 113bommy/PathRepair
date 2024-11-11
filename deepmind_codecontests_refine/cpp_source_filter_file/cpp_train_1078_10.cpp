#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n < 3) {
    printf("-1\n");
    return 0;
  } else if (n == 3) {
    printf("210\n");
    return 0;
  }
  int rest = 1;
  for (int i = 0; i < n; i++) rest = (rest * 10) % 210;
  int add = 210 - rest;
  if (add == 210) add = 0;
  int k = 0;
  if (add > 0) {
    if (add < 10)
      k = 1;
    else if (add < 100)
      k = 2;
    else
      k = 3;
  }
  for (int i = 0; i < n - k; i++) {
    if (!i)
      printf("1");
    else
      printf("0");
  }
  printf("%d\n", add);
  return 0;
}
