#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long int read() {
  long long int x;
  scanf("%lld", &x);
  return x;
}
const long long int N = 1e5;
int main() {
  long long int ca = read();
  for (long long int ci = 0; ci < ca; ci++) {
    long long int n = read(), d = read();
    n++;
    long long int x = sqrt(x);
    long long int y = x - 1, z = x + 1;
    if (x > 0 && (d / x + (d % x != 0) + x) <= n)
      puts("YES");
    else if (y > 0 && (d / y + (d % y != 0) + y) <= n)
      puts("YES");
    else if (z > 0 && (d / z + (d % z != 0) + z) <= n)
      puts("YES");
    else
      puts("NO");
  }
}
