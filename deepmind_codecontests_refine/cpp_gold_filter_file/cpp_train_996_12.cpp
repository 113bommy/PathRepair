#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j, flag = 0;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  for (i = 0; i <= 100; i++)
    for (j = 0; j <= 100; j++) {
      if (b + a * i == d + c * j) {
        printf("%d", b + a * i);
        return 0;
      }
    }
  if (flag == 0) printf("-1");
  return 0;
}
