#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &a, &b);
    double output;
    if (b == 0) {
      printf("1\n");
      continue;
    } else if (a == 0) {
      printf("0.5\n");
      continue;
    }
    if (a < 4 * b)
      output = (double)(a + 8 * b) / 16.0 / b;
    else
      output = (double)(a - b) / (double)a;
    printf("%lf\n", output);
  }
  return 0;
}
