#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  if (d == 0)
    printf("%d ", -1);
  else if (c > a + b)
    printf("%d ", -1);
  else if (a > d || b > d || c > d)
    printf("%d ", -1);
  else if ((a + b - c) >= d) {
    printf("%d ", -1);
  } else
    printf("%d ", d - (a + b - c));
  return 0;
}
