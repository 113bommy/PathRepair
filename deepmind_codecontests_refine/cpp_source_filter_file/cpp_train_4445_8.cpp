#include <bits/stdc++.h>
using namespace std;
long long n, H, ans = 0x7f7f7f7f7f7f7f;
bool check(long long mid) {
  long long need, ret;
  if (mid > H) {
    need = (mid + H) * (mid - H + 1) / 2 + (mid + 1) * mid / 2 - mid;
    ret = mid - H + mid;
  } else {
    need = (mid + 1) * mid / 2;
    ret = mid;
  }
  if (need > n) return false;
  long long last = n - need;
  ret += last / mid + (last % mid > 0);
  if (ret <= ans) {
    ans = ret;
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> H;
  long long left = 1, right = 1e9 + 7;
  while (left <= right) {
    long long mid = (left + right) >> 1;
    if (check(mid))
      left = mid + 1;
    else
      right = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
