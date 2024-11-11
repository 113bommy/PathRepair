#include <bits/stdc++.h>
using namespace std;
long long c1, c2, x, y;
bool check(long long mid) {
  long long ans1 = mid / (x * y);
  long long ans2 = mid / x;
  long long ans3 = mid / y;
  if (mid - ans1 >= c1 + c2 && mid - ans2 >= c1 && mid - ans3 >= c2) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cin >> c1 >> c2 >> x >> y;
  long long l = 0, r = 1e18;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}
