#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, i, x, y;
  scanf("%I64d ", &a);
  while (a--) {
    scanf("%I64d %I64d", &x, &y);
    i = ceil(cbrt(x * y));
    if (x % i == 0 && y % i == 0 && (x * y) == i * i * i) {
      printf("Yes\n");
    } else
      printf("No\n");
  }
}
