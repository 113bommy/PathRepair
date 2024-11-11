#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &a, &b);
    if (a == 0 && b == 0) {
      printf("1.0000000000\n");
      continue;
    }
    if (a == 0 && b != 0) {
      printf("0.0000010000\n");
      continue;
    }
    if (a - 4 * b >= 0)
      printf("%.10f0\n", 1.0 - 1.0 * b / a);
    else
      printf("%.10f0\n", 0.5 + a / 16.0 / b);
  }
  return 0;
}
