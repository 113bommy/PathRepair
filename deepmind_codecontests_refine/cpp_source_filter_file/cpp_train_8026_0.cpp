#include <bits/stdc++.h>
int main() {
  int no_of_points;
  scanf("%d", &no_of_points);
  int maximum_sum = 0;
  while (no_of_points--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int maximum_sum = (maximum_sum > x + y ? maximum_sum : x + y);
  }
  printf("%d\n", maximum_sum);
  return 0;
}
