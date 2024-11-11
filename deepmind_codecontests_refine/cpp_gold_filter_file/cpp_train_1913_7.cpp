#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
long long chao(long long t) {
  if (t <= 0) return 0;
  long long ans = t * t;
  return ans;
}
long long chong(long long t) {
  if (t <= 0) return 0;
  long long ans = t * (t + 1) / 2;
  return ans;
}
long long ji(long long t) {
  long long ans = 2 * t * t + 2 * t + 1;
  ans -=
      (chao(x + t - n) + chao(t - x + 1) + chao(y + t - n) + chao(t - y + 1));
  ans += (chong(t - (x - 1 + y - 1) - 1) + chong(t - (x - 1 + n - y) - 1) +
          chong(t - (n - x + y - 1) - 1) + chong(t - (n - x + n - y) - 1));
  return ans;
}
int main() {
  long long c, r, l;
  cin >> n >> x >> y >> c;
  long long ans, mid, tem;
  r = 2 * n, l = 0;
  while (l < r) {
    mid = (l + r) / 2;
    tem = ji(mid);
    if (tem >= c)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
