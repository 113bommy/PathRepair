#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int cou = 0;
  if (n == 1) {
    if (x == 1)
      puts("1");
    else
      puts("0");
  } else {
    for (int i = 1; i <= n; i++)
      if (!(x % i) && x / i <= n) cou++;
    printf("%d\n", cou);
  }
  return 0;
}
