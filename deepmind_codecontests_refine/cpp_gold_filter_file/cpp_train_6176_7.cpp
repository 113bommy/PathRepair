#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, k, a, b;
long long tmp, anss = 0;
long long binary() {
  long long x1, y1;
  long long l = 0, r = 1000000000, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    x1 = x + a * mid;
    y1 = y + b * mid;
    if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  x += a * ans;
  y += b * ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> x >> y;
  cin >> k;
  while (k--) {
    cin >> a >> b;
    anss += binary();
  }
  cout << anss;
  return 0;
}
