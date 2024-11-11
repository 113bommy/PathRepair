#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long cnt = 1;
    if (n == 1) {
      printf("0\n");
      continue;
    }
    for (int i = 1; i <= 64; i++) {
      if (cnt > k) {
        printf("%lld\n", i - 1 + (n - cnt - 1) / k + 1);
        break;
      }
      cnt *= 2;
      if (cnt >= n) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
