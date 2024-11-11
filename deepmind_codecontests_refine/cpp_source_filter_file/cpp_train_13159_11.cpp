#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 10;
long long n, m, c[10], a[1100], b[1100];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> c[0] >> c[1] >> c[2] >> c[3];
  cin >> n >> m;
  long long sum1 = 0, sum2 = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    if (c[0] * a[i] > c[1])
      sum1 += c[1];
    else
      sum1 += c[0] * a[i];
  }
  if (sum1 > c[3]) sum1 = c[2];
  for (long long j = 0; j < m; ++j) {
    cin >> b[j];
    if (c[0] * b[j] > c[1])
      sum2 += c[1];
    else
      sum2 += c[0] * b[j];
  }
  if (sum2 > c[2]) sum2 = c[2];
  if (sum1 + sum2 > c[3])
    cout << c[3] << "\n";
  else
    cout << sum1 + sum2 << "\n";
  return 0;
}
