#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, ans, sum, p, k, c, x, y;
char a[8][10] = {"vaporeon", "jolteon", "flareon", "espeon",
                 "umbreon",  "leafeon", "glaceon", "sylveon"};
char b[10];
int main() {
  scanf("%d\n", &n);
  gets(b);
  for (i = 0; i < 8; i++) {
    if (strlen(b) == n) {
      int ok = 1;
      for (j = 0; j < n; j++) {
        if (b[j] != '.' && (b[j] != a[i][j])) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        puts(a[i]);
        return 0;
      }
    }
  }
  return 0;
}
