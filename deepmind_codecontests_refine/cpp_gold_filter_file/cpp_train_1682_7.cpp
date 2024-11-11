#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 3e5;
long long n, m, a[LIMIT], p[LIMIT], d[LIMIT];
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%lld", &p[i]);
  }
  for (int i = 0; i < (n - 1); i++) {
    d[i] = a[i + 1] - a[i];
  }
  long long gcdAll = d[0];
  for (int i = 1; i < (n - 1); i++) {
    gcdAll = gcd(d[i], gcdAll);
  }
  for (int i = 0; i < m; i++) {
    if ((gcdAll % p[i]) == 0) {
      printf("%s\n%lld %d", "YES", a[0], (i + 1));
      return 0;
    }
  }
  printf("%s", "NO");
  return 0;
}
