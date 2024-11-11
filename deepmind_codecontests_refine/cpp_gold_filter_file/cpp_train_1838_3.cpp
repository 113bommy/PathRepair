#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long r, k, bs, a[N];
int n;
int main() {
  cin >> r >> k, bs = -k;
  while (r) {
    long long x = r / bs;
    if (bs * x > r) ++x;
    a[n++] = r - bs * x;
    r = x;
  }
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) printf("%lld ", a[i]);
  return 0;
}
