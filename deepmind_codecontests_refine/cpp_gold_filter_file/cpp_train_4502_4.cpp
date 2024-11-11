#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    int s;
    scanf("%d", &n);
    if (n < 2)
      s = 0;
    else if (n % 2 == 0)
      s = n / 2 - 1;
    else
      s = n / 2;
    printf("%d\n", s);
  }
}
