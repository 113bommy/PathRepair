#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) cin >> b[i];
  if (n == 1) {
    cout << "0";
    return 0;
  }
  vector<long long> dp1(n, 0), dp2(n, 0);
  dp1[n - 1] = (2 * n - 1) * a[n - 1] + (2 * n - 2) * b[n - 1];
  dp2[n - 1] = (2 * n - 1) * b[n - 1] + (2 * n - 2) * a[n - 1];
  long long sum = a[n - 1] + b[n - 1];
  long long sz = 2 * n - 4;
  for (long long i = n - 2; i >= 0; --i) {
    dp1[i] = (2 * n - 1) * a[i] + sz * b[i] + dp1[i + 1] - sum;
    dp2[i] = (2 * n - 1) * b[i] + sz * a[i] + dp2[i + 1] - sum;
    sum = sum + b[i] + a[i];
    sz -= 2;
  }
  sum = 0;
  long long ans = dp2[0];
  for (long long i = 0, x = 0; i < n - 1; ++i) {
    if (i & 1) {
      sum = a[i] * (x + 1) + b[i] * x + sum;
      ans = max(ans, sum + dp2[i + 1]);
    } else {
      sum = b[i] * (x + 1) + a[i] * x + sum;
      ans = max(ans, sum + dp1[i + 1]);
    }
    x += 2;
  }
  cout << ans;
  return 0;
}
