#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  int a[n + 1];
  long long ans = 0, p = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  ans = k * a[n - 1] + a[n - 2];
  ans = ans * (m / (k + 1));
  ans += m % (k + 1) * k * a[n - 1];
  cout << ans << endl;
  return 0;
}
