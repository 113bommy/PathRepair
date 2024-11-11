#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x, y;
  cin >> a >> b;
  if (a % 2 == 0)
    x = a / 2;
  else
    x = ceil(a / 2.0);
  if (x < b)
    printf("-1\n");
  else {
    if (x % b == 0)
      printf("%d\n", x);
    else {
      y = ((x / b) + 1) * b;
      if (y <= a) printf("%d\n", y);
    }
  }
  return 0;
}
