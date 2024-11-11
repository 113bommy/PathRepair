#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  scanf("%d", &n);
  t = sqrt(n);
  while (n > 0) {
    for (int i = n - t + 1; i <= n; i++) {
      if (i > 0) printf("%d ", i);
    }
    n -= t;
  }
}
