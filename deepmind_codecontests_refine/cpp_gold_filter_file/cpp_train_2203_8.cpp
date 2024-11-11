#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long mi = 1000000000000, mini = 1000000000000, ans;
    for (long long i = 0; i < n - k; i++) {
      long long mid = (a[i] + a[i + k]) / 2;
      mi = max(abs(a[i] - mid), abs(mid - a[i + k]));
      if (mi < mini) {
        ans = mid;
        mini = mi;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
