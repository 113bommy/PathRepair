#include <bits/stdc++.h>
using namespace std;
long long fac(long long n) {
  long long ans = 1;
  for (int i = n; i >= 1; i--) {
    ans *= n;
  }
  return ans;
}
long long ncr(long long n, long long r) {
  long long ans = fac(n) / (fac(n - r) * fac(r));
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long sum = 0;
    long long f = 0;
    long long cur = a[0];
    for (int i = 1; i < n; i++) {
      if (f == 0) {
        if (cur <= a[i]) {
          cur = a[i];
        } else {
          sum += a[i - 1];
          cur = a[i];
          f = 1;
        }
      } else {
        if (cur > a[i]) {
          cur = a[i];
        } else {
          sum -= a[i - 1];
          cur = a[i];
          f = 0;
        }
      }
    }
    if (f == 0) {
      sum += a[n - 1];
    }
    cout << sum << "\n";
  }
  return 0;
}
