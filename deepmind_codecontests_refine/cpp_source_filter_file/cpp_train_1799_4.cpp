#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, num;
  long long x, n, c;
  scanf("%d", &t);
  while (t--) {
    c = 1, c = 1;
    num = 0;
    scanf("%lld", &x);
    while (1) {
      c = n * (n + 1) / 2;
      if (x >= c) {
        x = x - c;
        num++;
        n = 2 * n + 1;
      } else
        break;
    }
    printf("%lld\n", num);
  }
  return 0;
}
