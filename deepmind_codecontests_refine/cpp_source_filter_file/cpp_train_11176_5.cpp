#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, a1, b1, c1;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &a1, &b1, &c1);
  if (a * b1 != a1 * b)
    puts("1");
  else if ((!a && !b && c) || (!a1 && !b1 && c1))
    puts("0");
  else if (a * b1 == a1 * b) {
    if (a * c1 == a1 * c || b * c1 == b1 * c)
      puts("-1");
    else
      puts("0");
  }
  return 0;
}
