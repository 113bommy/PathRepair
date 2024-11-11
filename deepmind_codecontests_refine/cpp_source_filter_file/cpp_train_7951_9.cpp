#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, count = 0, i, j, y;
  scanf("%lld", &n);
  for (i = 3; i <= n; i++) {
    for (j = 3; j <= n; j++) {
      y = sqrt((double)(i * i + j * j));
      if (y <= n && y * y == i * i + j * j) count += 1;
    }
  }
  printf("%lld\n", count);
  return 0;
}
