#include <bits/stdc++.h>
using namespace std;
long long a, b, n;
long long l, t, m;
bool check(long long r) {
  if ((a + (r - 1) * b) > t) return false;
  long long x;
  long long sum = 0;
  if ((r - l + 1) < m) {
    x = (r - l + 1) * t;
  } else
    x = m * t;
  sum = (a - b) * (r - l + 1) + b * r * (r + 1) / 2 - b * (l - 1) * l / 2;
  if (sum <= x)
    return true;
  else
    return false;
}
int main() {
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    if ((a + (l - 1) * b) > t) {
      cout << -1 << endl;
      continue;
    }
    long long high = 10000000;
    long long low = l;
    long long mid;
    long long res;
    int ctr = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      if (check(mid)) {
        res = mid;
        low = mid;
      } else {
        high = mid - 1;
      }
      if (ctr == 100) break;
      ctr++;
    }
    if (check(mid + 1))
      cout << mid + 1 << endl;
    else
      cout << mid << endl;
  }
  return 0;
}
