#include <bits/stdc++.h>
using namespace std;
const int mxk = 3e5 + 7;
int n, k;
int main() {
  int T;
  T = 1;
  while (T--) {
    scanf("%d", &n);
    k = 0;
    if (k == 0) {
      int ans = (n - 1) / 2;
      for (int k = 1; k <= n; k <<= 1) {
        if ((n - k) % 2 == 0) ans = min(ans, n - k / 2);
      }
      printf("%d\n", ans);
    } else {
      printf("%d\n", (n - 1) / 2 + 1);
    }
  }
}
