#include <bits/stdc++.h>
using namespace std;
long long A[200005];
long long mod = 1e9 + 7;
long long inv2 = 5e8 + 4;
void init() {
  A[0] = 1;
  for (long long i = 1; i <= 200000; i++) {
    A[i] = (A[i - 1] * i) % mod;
  }
}
signed main() {
  long long t;
  scanf("%lld", &t);
  long long n, m, k;
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    if (m > n * (n - 1) / 2) {
      cout << "No\n";
      continue;
    }
    if (k == 0) {
      cout << "No\n";
      continue;
    }
    if (n == 1) {
      cout << "Yes\n";
      continue;
    }
    if (m < n - 1 || k <= 2) {
      cout << "No\n";
      continue;
    }
    if (k > 3) {
      cout << "Yes\n";
      continue;
    }
    if (m == n * (n - 1) / 2) {
      cout << "Yes\n";
    } else
      cout << "No\n";
  }
  return 0;
}
