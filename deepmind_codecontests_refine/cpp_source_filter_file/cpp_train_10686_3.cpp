#include <bits/stdc++.h>
using namespace std;
long long n, Q;
int main() {
  long long x;
  scanf("%lld%lld", &n, &Q);
  while (Q--) {
    scanf("%d", &x);
    while (!(x & 1)) {
      x += n - (x >> 1);
    }
    printf("%lld\n", (x + 1) >> 1);
  }
}
