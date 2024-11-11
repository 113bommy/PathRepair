#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, c;
  scanf("%d", &n);
  if (n == 3) {
    printf("1 1 1");
  } else {
    a = 1;
    n -= 1;
    for (int i = 1; i < n; ++i) {
      b = i;
      c = n - i;
      if (b % 3 != 0 && c % 3 != 0) {
        printf("%d %d %d", a, b, c);
        return 0;
      }
    }
  }
}
