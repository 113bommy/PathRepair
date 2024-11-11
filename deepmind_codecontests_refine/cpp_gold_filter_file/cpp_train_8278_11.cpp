#include <bits/stdc++.h>
using namespace std;
bool can(long long a[], long long b[], long long md, long long tmp,
         long long n) {
  for (long long i = 0; i < n; i++) {
    long long lp = (a[i] * md) - b[i];
    if (lp > 0) tmp -= lp;
    if (tmp < 0) return false;
  }
  return true;
}
int main() {
  long long n, k, mx = INT_MIN, mn = INT_MAX;
  cin >> n >> k;
  long long a[n + 10], b[n + 10];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long mid, strt = 0, ind = 3000000000, ans = -1;
  while (strt <= ind) {
    mid = (strt + ind) / 2;
    if (can(a, b, mid, k, n)) {
      strt = mid + 1;
      ans = max(ans, mid);
    } else
      ind = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
