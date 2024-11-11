#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int inf = (int)1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;
const int N = (int)2e5;
long long n;
int q;
signed main() {
  scanf("%lld%d", &n, &q);
  for (int i = 0; i < q; ++i) {
    long long a;
    scanf("%lld", &a);
    long long bg, en, sz;
    if (a % 2) {
      printf("%d\n", (a + 1) / 2);
      continue;
    }
    if ((n - 1 & n) == 0)
      sz = (n >> 1) + 1;
    else {
      long long h = n;
      int pow_ = -1;
      while (h) {
        h >>= 1;
        ++pow_;
      }
      sz = (1ll << pow_) + 1;
    }
    bg = (n - sz) * 2 + 1;
    en = bg + sz - 1;
    if (a < bg) a = a / 2 + n;
    a -= bg - 1;
    while (a % 2 == 0 && bg + 1 < en) {
      a = en + a / 2;
      bg = en;
      a -= bg - 1;
      sz = sz / 2 + 1;
      en = bg + sz - 1;
    }
    if (a % 2 == 0) ++a;
    printf("%lld\n", (bg + a) / 2);
  }
  return 0;
}
