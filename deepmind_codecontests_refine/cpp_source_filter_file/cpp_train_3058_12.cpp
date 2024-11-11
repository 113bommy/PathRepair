#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  while (scanf("%d%d%d", &a, &b, &n) >= 1) {
    --n;
    a *= 10;
    bool found = 0;
    for (int it = 0; it < 9; it++, a++) {
      if (a % b) continue;
      found = 1;
      break;
    }
    if (found) {
      printf("%d", a);
      for (int i = 0; i < n; i++) printf("0");
      printf("\n");
    } else
      printf("-1");
  }
  return 0;
}
