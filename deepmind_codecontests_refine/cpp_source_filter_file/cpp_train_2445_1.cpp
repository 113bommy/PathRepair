#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
bool can(long long l, long long r, long long t, long long m) {
  long long f = a + b * (l - 1), la = a + b * (r - 1);
  long long sum = (f + la) * (r - l + 1) / 2;
  return (la <= t && sum <= m * t);
}
int main() {
  cin >> a >> b >> n;
  while (n--) {
    long long l, le, t, m, r = 1000000;
    r *= r * r;
    cin >> l >> t >> m;
    le = l;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (!can(le, mid, t, m))
        r = mid - 1;
      else
        l = mid + 1;
    }
    long long ans;
    if (r > le)
      ans = r;
    else if (r == le && can(le, r, t, m))
      ans = r;
    else
      ans = -1;
    cout << ans << endl;
  }
  return 0;
}
