#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  swap(x, y);
  if (n > x) {
    printf("-1");
    return 0;
  }
  long long k = x - n + 1;
  if (y / k <= k) {
    printf("%I64d\n", k);
    for (int i = 1; i < n; ++i) printf("1\n");
  } else {
    if (k * k + n - 1 >= y) {
      printf("%I64d\n", k);
      for (int i = 1; i < n; ++i) printf("1\n");
    } else
      printf("-1");
  }
  return 0;
}
