#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  if (m > n) {
    cout << -1 << "\n";
    return 0;
  }
  long long left = 1, right = n / m;
  while (right > left) {
    long long mid = (left + right) / 2;
    if (m * mid - l >= l)
      right = mid;
    else
      left = mid + 1;
  }
  if (m * left - k >= l)
    cout << left << "\n";
  else
    cout << -1 << "\n";
  return 0;
}
