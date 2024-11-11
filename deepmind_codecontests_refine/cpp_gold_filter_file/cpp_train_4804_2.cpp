#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int k, n = 1199, a[N];
int main() {
  scanf("%d", &k);
  int final;
  for (final = 899999;; ++final) {
    if ((final + k) % n == 0) {
      a[0] = (final + k) / n;
      a[n - 1] = final;
      break;
    }
  }
  for (int i = 2; i < n - 1; i += 2) {
    a[i] = a[i - 2] + 1;
  }
  for (int i = 1; i < n - 1; i += 2) {
    a[i] = -a[i + 1];
  }
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], " \n"[i == n - 1]);
  }
  return 0;
}
