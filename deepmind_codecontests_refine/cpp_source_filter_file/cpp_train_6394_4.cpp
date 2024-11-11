#include <bits/stdc++.h>
using namespace std;
long long a, b, w, x, c;
long long calc(long long t) {
  if (x * t - b <= 0) return 0;
  return (x * t - b - 1) / w + 1;
}
bool check(long long t) { return c - t <= a - calc(t); }
int main() {
  cin >> a >> b >> w >> x >> c;
  long long l = -1, r = 1e12, mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
}
