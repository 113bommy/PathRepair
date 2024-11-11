#include <bits/stdc++.h>
using namespace std;
long long n, a[100100], b[100100];
int main() {
  long long t = 1;
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  while (t <= n) t <<= 1;
  for (long long i = 1; i < n; ++i) {
    while (t > n - i) t >>= 1;
    b[i] = b[i - 1] + a[i];
    a[i + t] += a[i];
  }
  for (long long i = 1; i < n; ++i) cout << b[i] << "\n";
  return 0;
}
