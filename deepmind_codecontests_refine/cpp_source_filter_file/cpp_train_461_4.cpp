#include <bits/stdc++.h>
using namespace std;
int possible(long long cnt1, long long cnt2, long long x, long long y,
             long long v) {
  long long fx = v / x;
  long long fy = v / y;
  long long fxy = v / (x * y);
  long long nxy = v - fx - fy - fxy;
  long long nx = v - fx - nxy;
  long long ny = v - fy - nxy;
  if (cnt1 > nx) {
    cnt1 = cnt1 - nx;
    if (cnt1 > nxy) {
      return 0;
    }
    nxy -= cnt1;
  }
  if (cnt2 > ny) {
    cnt2 = cnt2 - ny;
    if (cnt2 > nxy) {
      return 0;
    }
  }
  return 1;
}
int main() {
  long long l = 1;
  long long r = 1000000000000000000ll;
  long long ans = -1;
  long long cnt1, cnt2, x, y;
  cin >> cnt1 >> cnt2 >> x >> y;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (possible(cnt1, cnt2, x, y, mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}
