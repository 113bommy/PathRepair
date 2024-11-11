#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t;
  cin >> n >> t;
  long long a[n];
  long long b[n];
  long long ans = 0;
  long long mn = INT_MAX;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j <= 100000; j++) {
      if (((b[i] * j) + a[i]) - t < mn && ((b[i] * j) + a[i]) - t >= 0) {
        mn = ((b[i] * j) + a[i]) - t;
        ans = i + 1;
      }
    }
  }
  cout << ans << "\n";
}
