#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  scanf("%d", &n);
  if (n % 2 == 1)
    printf("%d\n", n / 2);
  else {
    for (int i = 30; i >= 0; i--) {
      if (n >= (1 << i)) {
        n -= (1 << i);
        break;
      }
    }
    printf("%d\n", n / 2);
  }
  return 0;
}
