#include <bits/stdc++.h>
using namespace std;
long long cal(long long x, long long p) {
  if (p & 1) return (p + 1) >> 1;
  long long t = x >> 1;
  long long np = (x - t) - (t - p / 2);
  return t + cal(x - t, np);
}
int main() {
  long long n;
  int q;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    long long p;
    scanf("%I64d", &p);
    printf("%I64d\n", cal(n, p));
  }
  return 0;
}
