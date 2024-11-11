#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  long long bit[32];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
    for (int j = 0; j < 32; ++j) bit[j] = 0;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &x);
      int r = 0;
      while (x >>= 1) {
        r++;
      }
      bit[r] += 1;
    }
    long long cunt = 0;
    for (int j = 0; j < 32; ++j) {
      cunt += bit[j] * (bit[j] - 1) / 2;
    }
    printf("%lld\n", cunt);
  }
  return 0;
}
