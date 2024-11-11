#include <bits/stdc++.h>
using namespace std;
long long int BS(long long int n, long long int m) {
  long long int level, lo = 1LL, hi = 1e9, mid, res = 0LL, tot, bad, add, x;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    x = mid;
    add = (x - 1) * m;
    bad = (x * m) + ((x * (x + 1)) / 2);
    tot = n - bad + add;
    if (tot <= 0) {
      res = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return res;
}
int main() {
  long long int i, j, k, n, m, ans, day;
  scanf("%lld %lld", &(n), &(m));
  if (n <= m) {
    cout << n << endl;
    return 0;
  }
  day = m;
  ans = day + BS(n, m);
  cout << ans << endl;
  return 0;
}
