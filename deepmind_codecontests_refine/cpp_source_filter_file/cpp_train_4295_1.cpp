#include <bits/stdc++.h>
const long double pi = 3.1415926536;
using namespace std;
long double hot, cold, t;
long double avg(long double x, long double y) {
  return (long double)(x + y) / 2.0;
}
long double f(int i) {
  return (long double)(i * hot + (i - 1) * cold) / (long double)(2.0 * i - 1);
}
void solve() {
  int ans = 1;
  cin >> hot >> cold >> t;
  if (avg(hot, cold) >= t) {
    cout << 2 << "\n";
    return;
  }
  if (hot == t) {
    cout << 1 << "\n";
    return;
  }
  int low = 0, high = 1000000000, mid;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (f(mid) > t) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  long double eps = (long double)INT_MAX;
  for (int i = max(0, low - 1); i < low + 1; i++) {
    if (abs(f(i) - t) < eps) {
      eps = abs(f(i) - t);
      ans = i;
    }
  }
  cout << 2 * ans - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
