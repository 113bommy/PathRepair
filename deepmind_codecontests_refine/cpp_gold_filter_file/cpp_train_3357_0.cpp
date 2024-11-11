#include <bits/stdc++.h>
using namespace std;
long long q, n;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long left = 1, right = 2e9 + 1e6;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (mid % n == 0) {
      if (mid - (mid / n) < k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      if (mid - (mid / n) < k) {
        left = mid + 1;
      } else if (mid - (mid / n) > k) {
        right = mid - 1;
      } else {
        cout << mid << "\n";
        ;
        return;
      }
    }
  }
  return;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
