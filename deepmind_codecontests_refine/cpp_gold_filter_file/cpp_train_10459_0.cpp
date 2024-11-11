#include <bits/stdc++.h>
using namespace std;
int a;
int b;
int main() {
  scanf("%d %d", &a, &b);
  if (a == b) {
    printf("infinity\n");
    return 0;
  }
  if (a < b) {
    printf("0\n");
    return 0;
  }
  a -= b;
  int x = 0;
  int i;
  for (i = 1; i * i < a; i++) {
    if (a % i == 0) {
      if (i <= b) {
        if (a / i > b) x += 1;
      } else
        x += 2;
    }
  }
  if (i * i == a && i > b) {
    x++;
  }
  printf("%d\n", x);
  return 0;
}
