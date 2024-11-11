#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, d;
    cin >> n >> d;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int count = 0;
    for (long long int i = 1; i < n; i++) {
      long long int ext = i - 0;
      long long int st = 0;
      long long int end = a[i];
      long long int ans = 0;
      while (st <= end) {
        long long int mid = (st + end) / 2;
        if (mid * ext > d - count) {
          end = mid - 1;
        } else {
          ans = mid;
          st = mid + 1;
        }
      }
      count += (ans * ext);
      a[0] += ans;
    }
    cout << a[0] << endl;
  }
  return 0;
}
