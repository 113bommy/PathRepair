#include <bits/stdc++.h>
int main() {
  int red, blue, reminder, result, sum1, sum2;
  scanf("%d%d", &red, &blue);
  if (blue > red) {
    sum1 = red;
    blue = blue - sum1;
    result = blue / 2;
    printf("%d %d\n", sum1, result);
  } else if (blue < red) {
    sum1 = blue;
    red = red - sum1;
    result = red / 2;
    printf("%d %d\n", sum1, result);
  } else {
    printf("%d 0\n", red);
  }
}
