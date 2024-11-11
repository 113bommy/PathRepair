#include <bits/stdc++.h>
using namespace std;
int n, m;
int lucky(int n) {
  int a[10];
  int x = 0;
  int res = 0;
  while (n) {
    if (n % 10 == 4 || n % 10 == 7) {
      a[x] = n % 10;
      x++;
    }
    n /= 10;
  }
  for (x--; x >= 0; x--) res = res * 10 + a[x];
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (; n < 10000000; n++) {
    if (lucky(n) == m) {
      printf("%d\n", n);
      return 0;
    }
  }
  return 0;
}
