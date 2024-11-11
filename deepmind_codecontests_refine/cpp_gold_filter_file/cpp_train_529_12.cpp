#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, l, a;
  long long int ans = 0;
  cin >> n >> l >> a;
  if (n == 0) {
    cout << l / a;
    return 0;
  }
  long long int p[n], q[n];
  for (long long int i = 0; i < n; i++) {
    cin >> p[i] >> q[i];
  }
  ans = ans + p[0] / a;
  for (long long int i = 0; i < n - 1; i++) {
    ans = ans + (p[i + 1] - (p[i] + q[i])) / a;
  }
  ans += (l - (p[n - 1] + q[n - 1])) / a;
  cout << ans;
  return 0;
}
