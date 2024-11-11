#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int main() {
  scanf("%d%d", &n, &m);
  if (m == 3) {
    if (n == 3) puts("0 0\n100 0\n100 100");
    if (n == 4) puts("0 0\n100 0\n100 100\n50 1");
    if (n == 5) puts("-1");
    if (n == 6) puts("-1");
  } else {
    t = 0;
    for (int i = (0); i < (m); i++) {
      t += i;
      printf("%d %d\n", i, t);
    }
    t = 0;
    for (int i = (0); i < (n - m); i++) {
      t += i;
      printf("%d %d\n", 100000000 - i, t);
    }
  }
  return 0;
}
