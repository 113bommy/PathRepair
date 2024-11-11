#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, k1, k2, n, x = 0, y = 0;
  scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
  int sum = a1 * (k1 - 1) + a2 * (k2 - 1);
  if (sum >= n)
    y = 0;
  else
    y = n - sum;
  if (k1 < k2) {
    int r;
    x = min(a1, n / k1);
    r = n - x * k1;
    x += min(a2, r / k2);
  } else if (k1 > k2) {
    int r;
    x = min(a2, n / k2);
    r = n - x * k2;
    x += min(a1, r / k1);
  } else {
    x = min(a1 + a2, n / k1);
  }
  printf("%d %d", y, x);
}
