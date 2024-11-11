#include <bits/stdc++.h>
using namespace std;
int T;
long long r, b, k, g;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &r, &b, &k);
    if (r > b) swap(r, b);
    g = gcd(r, b);
    r /= g, b /= g;
    if ((k - 1) * r + 1 >= b)
      printf("OBEY\n");
    else
      printf("REBLE\n");
  }
  return 0;
}
