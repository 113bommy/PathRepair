#include <bits/stdc++.h>
using namespace std;
long long a[2005], b[2005];
long long n, k, p;
long long myFn(long long i) {
  long long ret = LLONG_MIN;
  for (long long j = 1; j <= n; j++) {
    ret = max(ret, abs(a[j] - b[j + i - 1]) + abs(b[j + i - 1] - p));
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  long long precision = numeric_limits<double>::digits10;
  ;
  cin >> n >> k >> p;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= k; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  long long ans = LLONG_MAX;
  for (long long i = 1; i <= k - n + 1; i++) {
    ans = min(ans, myFn(i));
  }
  cout << ans << endl;
}
