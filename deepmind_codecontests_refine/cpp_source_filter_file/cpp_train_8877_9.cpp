#include <bits/stdc++.h>
using namespace std;
int T, a, b, c, d;
int x[5];
int main() {
  int i;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    x[1] = a + b, x[2] = a + d, x[3] = c + b, x[4] = c + d;
    sort(x + 1, x + 5);
    printf("%d\n", x[3]);
  }
  return 0;
}
