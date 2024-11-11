#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long solve(long long mid, long long k, long long x, long long a,
                long long y, long long b, long long arr[], long long n) {
  if (y > x) {
    swap(y, x);
    swap(a, b);
  }
  long long p = mid / a;
  long long q = mid / b;
  long long lcm = a * b / gcd(a, b);
  long long l = mid / lcm;
  long long cnt1 = 0;
  for (int i = n - 1; i >= n - p; i--) {
    cnt1 += ((arr[i] * x) / 100);
  }
  for (int i = n - 1; i >= n - l; i--) cnt1 += ((arr[i] * y) / 100);
  for (int i = n - p - 1; i >= max((long long)0, n - p - q + l); i--)
    cnt1 += ((arr[i] * y) / 100);
  return cnt1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    sort(arr, arr + n);
    long long low = 1, high = n, ans = 1000000007;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      if (solve(mid, k, x, a, y, b, arr, n) >= k) {
        ans = min(ans, mid);
        high = mid - 1;
      } else
        low = mid + 1;
    }
    if (ans == 1000000007)
      cout << "-1" << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
