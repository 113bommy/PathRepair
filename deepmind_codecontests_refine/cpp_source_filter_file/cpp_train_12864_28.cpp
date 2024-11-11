#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  b[0] = 20;
  cout << b[0] << endl;
  for (long long i = 1; i < n; i++) {
    b[i] = 20;
    long long x = upper_bound(a, a + i, a[i] - 90 + 1) - a;
    long long y = upper_bound(a, a + i, a[i] - 1440 + 1) - a;
    if (x == 0)
      b[i] = min(b[i], 50 - b[i - 1]);
    else
      b[i] = min(b[i], b[x - 1] + 50 - b[i - 1]);
    if (y == 0)
      b[i] = min(b[i], 120 - b[i - 1]);
    else
      b[i] = min(b[i], b[y - 1] + 120 - b[i - 1]);
    cout << b[i] << endl;
    b[i] += b[i - 1];
  }
  return 0;
}
