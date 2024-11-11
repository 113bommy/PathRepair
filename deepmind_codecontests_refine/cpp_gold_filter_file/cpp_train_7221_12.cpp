#include <bits/stdc++.h>
using namespace std;
int main() {
  int ara[100][100], a, b, i, j;
  for (i = 1; i <= 5; i++) {
    for (j = 1; j <= 5; j++) {
      scanf("%d", &ara[i][j]);
      if (ara[i][j] == 1) {
        a = i;
        b = j;
      }
    }
  }
  int c = abs(3 - a) + abs(3 - b);
  printf("%d\n", c);
  return 0;
}
