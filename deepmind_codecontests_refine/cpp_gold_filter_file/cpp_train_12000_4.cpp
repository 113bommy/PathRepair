#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, mod = 1e9 + 7, inf = 0x3f3f3f3f3f3f3f3f,
                Max = 1e6;
long long n, k;
void work() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++)
      if (i % 2)
        printf("0 ");
      else
        printf("%lld ", 1ll << (i + j));
    cout << endl;
  }
  long long q;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld", &k);
    printf("1 1");
    cout << endl;
    k -= 1ll << 2;
    for (long long x = 1, y = 1; x + y + 1 <= n + n;) {
      if (x % 2 == 0) {
        if (k & (1ll << (x + y + 1)))
          x++;
        else
          y++;
      } else {
        if (k & (1ll << (x + y + 1)))
          y++;
        else
          x++;
      }
      k -= 1ll << (x + y);
      printf("%lld %lld", x, y);
      cout << endl;
    }
  }
  return;
}
int main() {
  work();
  return 0;
}
