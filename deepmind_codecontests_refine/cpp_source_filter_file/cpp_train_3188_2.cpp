#include <bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b) {
  if (b == 0) return a;
  gcd(b, a % b);
}
int main() {
  long long n, k;
  int index = 1;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < k; i++) index *= 10;
  printf("%lld\n", n * index / gcd(n * index, n));
}
