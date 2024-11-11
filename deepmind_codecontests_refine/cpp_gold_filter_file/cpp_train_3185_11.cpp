#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a == b)
    printf("1\n");
  else {
    int wt = 0;
    while (b >= a) {
      a *= 3;
      b *= 2;
      wt++;
    }
    printf("%d\n", wt);
  }
}
