#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  printf("YES\n");
  int a, b, c, d;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (c < 0) c *= -1;
    if (d < 0) d *= -1;
    if ((a & 1) && (b & 1))
      printf("4\n");
    else if ((a & 1) == 0 && (b & 1))
      printf("1\n");
    else if ((a & 1) && (b & 1) == 0)
      printf("2\n");
    else
      printf("3\n");
  }
  return 0;
}
