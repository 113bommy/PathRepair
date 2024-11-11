#include <bits/stdc++.h>
using namespace std;
int fac[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  long long res = 0;
  for (int i = a; i <= b; i++) {
    int x = i;
    while (x) {
      int r = x % 10;
      x /= 10;
      res += fac[r];
    }
  }
  printf("%I64d\n", res);
  return 0;
}
