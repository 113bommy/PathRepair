#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long a[500005];
long long p[500005];
long long t[500005];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n / 2 + n % 2; i++) {
    cin >> a[i];
  }
  long long x;
  cin >> x;
  for (long long i = n / 2 + n % 2 + 1; i <= n; i++) {
    a[i] = x;
  }
  for (long long i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i];
  }
  long long sum = p[n];
  if (x >= 0) {
    if (sum > 0) {
      cout << n;
    } else {
      cout << -1;
    }
    return 0;
  }
  for (long long i = 1; i <= n / 2 + n % 2; i++) {
    long long l = n / 2 + 1;
    long long r = n - i + 1;
    long long ans = 0;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (p[i + mid - 1] - p[i - 1] > 0) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    t[i] = ans;
  }
  for (int i = 1; i <= n; i++) {
  }
  long long lim = 1e9;
  for (long long i = 1; i <= n / 2 + n % 2; i++) {
    lim = min(lim, t[i]);
    if (i + lim >= n) {
      cout << lim;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
