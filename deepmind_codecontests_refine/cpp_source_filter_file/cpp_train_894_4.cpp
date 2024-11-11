#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int n, a, b, k;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (i >= n - i) break;
    for (int j = 2; j <= min(i, n - i); j++) {
      if (i % j && (n - i) % j == 0) {
        k = 1;
      }
    }
    if (k == 0) {
      a = i;
      b = n - i;
    }
    k = 0;
  }
  printf("%d %d", a, b);
  return 0;
}
