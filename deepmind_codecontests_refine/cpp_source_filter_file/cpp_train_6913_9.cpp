#include <bits/stdc++.h>
using namespace std;
int k, d, i;
int main() {
  scanf("%d%d", &k, &d);
  if (d == 0) {
    if (k == 1)
      puts("1");
    else
      puts("No solution");
    return 0;
  }
  printf("%d", d);
  for (i = 2; i <= k; i++) putchar('0');
  return 0;
}
