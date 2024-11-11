#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, c1, i;
  scanf("%d", &n);
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  i = n;
  c = c1 = 0;
  while (i % 10 != 0) {
    i++;
    c++;
  }
  i = n;
  while (i % 10 != 0) {
    i--;
    c1++;
  }
  if (c > c1) {
    printf("%d\n", n - c1);
    return 0;
  }
  printf("%d\n", n + c);
  return 0;
}
