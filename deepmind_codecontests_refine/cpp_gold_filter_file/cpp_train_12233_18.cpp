#include <bits/stdc++.h>
using namespace std;
long long y, k, n, j, i, x, q, d, m, c = 0, l, z, w, e, r, t;
long long lo(long long n) {
  long long k = 2, s = n;
  while (k * k <= n) {
    if (n % (k * k) == 0) return 0;
    k++;
  }
  return 1;
}
int main() {
  cin >> n;
  for (i = 1; i <= sqrt(n); i++)
    if (n % i == 0) {
      if (lo(i) == 1) m = max(i, m);
      if (lo(n / i) == 1) m = max(n / i, m);
    }
  cout << m;
  return 0;
}
