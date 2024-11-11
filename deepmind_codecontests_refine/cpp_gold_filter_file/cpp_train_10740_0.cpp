#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &n);
    int row;
    if (n > m)
      row = 3;
    else
      row = 2;
    int nn = min(n, m), mm = max(n, m);
    if (nn * 3 + 1 < mm) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= nn; i++) {
      printf("%d %d\n", 2 * i, row);
      printf("%d %d\n", 2 * i + 1, row);
    }
    mm -= nn;
    if (mm > 0) printf("1 %d\n", row), mm--;
    int line = 2;
    int tim = 1;
    while (mm--) {
      tim = (tim + 1) % 2;
      if (tim == 0)
        printf("%d %d\n", line, row - 1);
      else {
        printf("%d %d\n", line, row + 1);
        line += 2;
      }
    }
  }
  return 0;
}
