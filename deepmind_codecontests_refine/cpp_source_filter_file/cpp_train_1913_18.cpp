#include <bits/stdc++.h>
using namespace std;
long long n, x, y, c;
long long cal(long long n, long long m, long long t) {
  if (n < m) swap(n, m);
  if (t <= m)
    return ((t + 1) * t) / 2;
  else {
    long long v = ((m - 1) * m) / 2;
    t -= (m - 1);
    if (t <= n - m + 1)
      return v + t * m;
    else {
      v += (n - m + 1) * m;
      t -= (n - m + 1);
      if (t <= m - 1)
        v += ((2 * m - 1 - t) * t) / 2;
      else
        v += ((m - 1) * m) / 2;
    }
    return v;
  }
}
bool check(long long t) {
  long long sum =
      (long long)1 - (min(x, t + 1) + min(t + 1, y) + min(n - x + 1, t + 1) +
                      min(n - y + 1, t + 1));
  sum += cal(x, y, t + 1);
  sum += cal(n - x + 1, n - y + 1, t + 1);
  sum += cal(n - x + 1, y, t + 1);
  sum += cal(x, n - x + 1, t + 1);
  return sum >= c;
}
int main() {
  cin >> n >> x >> y >> c;
  long long l = 0, r = 2 * n;
  while (r >= l) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << r + 1 << endl;
}
