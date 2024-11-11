#include <bits/stdc++.h>
using namespace std;
int q;
long long n;
int main() {
  cin >> n >> q;
  while (q--) {
    long long v;
    scanf("%lld", &v);
    if (v & 1) {
      printf("%lld\n", (v + 1) >> 1);
      continue;
    }
    if (n * 2 == v + 1) {
      printf("%lld\n", n);
      continue;
    }
    long long f = ((n * 2 - v) >> 1);
    long long g = log2(f);
    f = f - (1 << g) + 1;
    if (f == 1)
      printf("%lld\n", n);
    else {
      while ((f & 1)) --g, f = f + 1 >> 1;
      if (!(f & 1)) {
        printf("%lld\n", n - ((1 << (g - 1)) + f / 2 - 1));
        continue;
      }
    }
  }
  return 0;
}
