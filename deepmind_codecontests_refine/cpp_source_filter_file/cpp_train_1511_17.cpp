#include <bits/stdc++.h>
using namespace std;
long long a[2000007];
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }
  long long i, j, k, n, m, c, t, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    a[k]++;
  }
  long long ans = 0;
  for (i = 0; i <= 200000; i++) {
    k = a[i] / 2;
    a[i] -= k + k;
    a[i + 1] += k;
    ans += a[i];
  }
  cout << ans << "\n";
}
