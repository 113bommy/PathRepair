#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  long long m = 1e9;
  long long sum = 0;
  for (long long i = 0; i < n; ++i) cin >> a[i], m = min(m, a[i]), sum += a[i];
  for (long long i = 0; i < n; ++i) {
    if ((a[i] - m) % k != 0) {
      cout << -1;
      return 0;
    }
  }
  long long l = sum - m * n;
  cout << l / k;
}
