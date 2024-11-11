#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z, dd = 0;
  cin >> a >> b >> c >> x >> y >> z;
  if (x > a && y > b && z > c) {
    printf("Yes\n");
    return 0;
  }
  while (a > x) {
    a -= 2;
    dd++;
  }
  while (b > y) {
    b -= 2;
    dd++;
  }
  while (c > z) {
    c -= 2;
    dd++;
  }
  if (dd + a + c + b == x + y + z)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
