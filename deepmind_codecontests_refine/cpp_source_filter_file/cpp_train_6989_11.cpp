#include <bits/stdc++.h>
using namespace std;
const int mx = 2000;
const int mod = 1e9 + 7;
const int N = 9e5;
int n, k;
int main() {
  scanf("%d", &k);
  printf("%d\n", mx);
  for (int i = 1; i < mx; i++) {
    long long ret = 1ll * (i + 1) * N + k;
    if (ret <= 1ll * 1e6 * i) {
      for (int j = 1; j < mx - i; j++) printf("-1000000 ");
      printf("%d ", N);
      int c = i;
      while (c--) {
        if (ret >= 1e6)
          printf("1000000 "), ret -= 1e6;
        else {
          printf("%d ", ret);
          ret = 0;
        }
      }
      return 0 * puts("");
    }
  }
  return 0 * puts("");
}
