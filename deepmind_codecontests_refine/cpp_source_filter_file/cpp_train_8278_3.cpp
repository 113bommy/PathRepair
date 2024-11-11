#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1000010], b[1000010];
int check(long long x) {
  long long cnt = 0LL;
  for (int j = 0; j < n; j++) {
    cnt += max(x * a[j] - b[j], 0LL);
    if (cnt > k) {
      return 0;
    }
  }
  if (cnt <= k)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  long long l = 0, r = 1000000010LL, m, ans = 0LL;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (check(m) == 1) {
      ans = max(ans, m);
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
