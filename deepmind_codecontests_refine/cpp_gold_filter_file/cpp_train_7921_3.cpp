#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a > b) swap(a, b);
  long long total = 1ll * a * b;
  if (a == 1) {
    b %= 6;
    if (b == 1 || b == 5)
      printf("%lld\n", total - 1);
    else if (b == 2 || b == 4)
      printf("%lld\n", total - 2);
    else if (b == 3)
      printf("%lld\n", total - 3);
    else
      printf("%lld\n", total);
  } else if (a == 2) {
    if (b == 2)
      printf("%lld\n", total - 4);
    else if (b == 3)
      printf("%lld\n", total - 2);
    else if (b == 7)
      printf("%lld\n", total - 2);
    else
      printf("%lld\n", total);
  } else {
    printf("%lld\n", (total & 1) ? total - 1 : total);
  }
  return 0;
}
