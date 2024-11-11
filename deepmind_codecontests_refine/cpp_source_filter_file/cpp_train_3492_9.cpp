#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 1)
    printf("%d\n", max(n / 2 - 1, 0));
  else {
    n = n / 2;
    int i = 1, tmp = n;
    while (tmp > 0) {
      tmp /= 2;
      i *= 2;
    }
    printf("%d\n", n - i / 2);
  }
}
