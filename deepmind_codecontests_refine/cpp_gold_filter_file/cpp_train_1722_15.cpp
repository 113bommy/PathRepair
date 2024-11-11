#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void fun() {
  int n, k;
  cin >> n >> k;
  int lo = 0, hi = 10000;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] >= mid * a[i]) continue;
      sum += mid * a[i] - b[i];
    }
    if (sum <= k) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  long long int t = 1;
  while (t--) {
    fun();
  }
  return 0;
}
