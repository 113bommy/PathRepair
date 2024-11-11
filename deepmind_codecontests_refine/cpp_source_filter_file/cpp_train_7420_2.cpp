#include <bits/stdc++.h>
using namespace std;
int xx[4] = {1, 2, 2, 0};
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    if (n == 1 || m == 1) {
      printf("%d\n", n * m);
    } else {
      if (n == 2 || m == 2) {
        int x = (n > m ? n : m);
        x = x / 4 * 2 + xx[x % 4];
        printf("%d\n", 2 * x);
      } else {
        printf("%d\n", (n * m + 1) / 2);
      }
    }
  }
  return 0;
}
