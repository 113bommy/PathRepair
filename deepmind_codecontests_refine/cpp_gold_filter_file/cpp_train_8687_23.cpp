#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a[m + 1], i, ans = 0;
  for (i = 0; i <= m; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    long long int c = 0;
    for (long long int j = 0; j < n; j++) {
      if ((1 << j & a[m]) ^ (1 << j & a[i])) c++;
    }
    if (c <= k) ans++;
  }
  cout << ans << endl;
  return 0;
}
