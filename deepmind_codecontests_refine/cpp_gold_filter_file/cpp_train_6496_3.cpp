#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[m + 5];
  for (long long i = 0; i < m; i++) cin >> a[i];
  long long x, y = 1, k, ans = 0;
  for (long long i = 0; i < m; i++) {
    x = a[i];
    k = x - y;
    if (k >= 0)
      ans += k;
    else
      ans += (n + k);
    y = x;
  }
  cout << ans << endl;
}
