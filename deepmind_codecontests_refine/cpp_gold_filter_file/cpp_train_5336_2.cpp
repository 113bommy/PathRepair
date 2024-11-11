#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, y = 0;
    scanf("%d", &n);
    int i;
    for (i = 2; i < sqrt(n) + 1; i++) {
      if (n % i == 0) {
        printf("%d %d", n / i, n - (n / i));
        y = 1;
        break;
      }
    }
    if (y == 0) printf("%d %d", 1, n - 1);
    printf("\n");
  }
  return 0;
}
