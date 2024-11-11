#include <bits/stdc++.h>
using namespace std;
long long int prime(long long int x) {
  for (long long int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
long long int sol(long long int n, long long int k) {
  if (k == 0 || k == n)
    return 1;
  else
    return sol(n - 1, k - 1) + sol(n - 1, k);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, x, y, k = 0;
  cin >> n >> x >> y;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) {
    if (a[i] * x % y == 0)
      cout << 0 << " ";
    else {
      if (a[i] * x / y == 0)
        cout << a[i] << " ";
      else
        cout << a[i] * x % y << " ";
    }
  }
}
