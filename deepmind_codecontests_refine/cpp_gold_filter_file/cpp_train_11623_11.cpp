#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, max = 0;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (d < a && d < b && 2 * d >= c && d <= 2 * c) {
    if (c >= d)
      max = c;
    else
      max = d;
    printf("%d %d %d", 2 * a, 2 * b, max);
  } else {
    printf("%d", -1);
  }
}
