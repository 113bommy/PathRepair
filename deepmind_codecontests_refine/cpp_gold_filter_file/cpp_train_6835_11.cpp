#include <bits/stdc++.h>
using namespace std;
int q;
unsigned long long t, x, k;
long long pos[100];
int main() {
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%llu", &t);
    if (t < 3) {
      scanf("%llu%llu", &x, &k);
      int j;
      for (j = 62; j >= 0; j--) {
        if ((1uLL << j) & x) {
          k = ((k % (1uLL << j)) + (1uLL << j)) % (1uLL << j);
          pos[j] = (pos[j] + k) % (1uLL << j);
          break;
        }
      }
      if (t == 2)
        for (int p = j + 1; p < 63; ++p) {
          k = k * 2 % (1ull << p);
          pos[p] = (pos[p] + k) % (1uLL << p);
        }
    } else {
      scanf("%llu", &x);
      for (int j = 62; j >= 0; j--) {
        if ((1uLL << j) & x) {
          unsigned long long cur = (x + pos[j]);
          while (cur >= (1LL << (j + 1))) cur -= (1LL << j);
          for (int k = j; k >= 0; k--) {
            unsigned long long ans = (cur - pos[k]);
            if (ans < (1uLL << k)) ans += 1uLL << k;
            printf("%llu ", ans);
            cur /= 2;
          }
          printf("\n");
          break;
        }
      }
    }
  }
}
