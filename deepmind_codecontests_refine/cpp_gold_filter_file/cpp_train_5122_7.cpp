#include <bits/stdc++.h>
using namespace std;
int nb_ones(long long x) { return __builtin_popcount(x); }
int main() {
  long long n, p;
  scanf("%I64d", &(n));
  scanf("%I64d", &(p));
  for (long long ans = 1; ans < 40; ans++) {
    if (n >= (p * ans) + ans) {
      if (nb_ones(n - (p * ans)) <= ans) {
        printf("%d\n", ans);
        return 0;
      }
    } else {
      break;
    }
  }
  puts("-1");
  return 0;
}
