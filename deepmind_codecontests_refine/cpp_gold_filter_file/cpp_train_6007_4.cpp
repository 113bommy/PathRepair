#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main(int argc, const char* argv[]) {
  int N;
  scanf("%d", &N);
  while (N-- > 0) {
    long long p, q, b;
    scanf("%lld%lld%lld", &p, &q, &b);
    q /= gcd(p, q);
    long long g = gcd(b, q);
    while (g > 1) {
      q /= g;
      g = gcd(q, g);
    }
    if (q > 1)
      printf("Infinite\n");
    else
      printf("Finite\n");
  }
  return 0;
}
