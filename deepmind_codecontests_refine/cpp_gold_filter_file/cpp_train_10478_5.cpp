#include <bits/stdc++.h>
using namespace std;
long long a[1000100];
long long pw(long long a, long long n) {
  if (n == 0) return 1;
  long long ans = pw(a, n / 2);
  ans = (ans * ans) % 1000000007;
  if (n & 1) return (ans * a) % 1000000007;
  return ans;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  long long pwr = 1, ans = 0, mx = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) pwr = (pwr * i) % 1000000007;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  sort(a + 1, a + n + 1);
  int c = 0;
  for (int i = 1; i <= n; i++) {
    while (c < n && a[i] > a[c]) c++;
    if (a[i] == mx) break;
    ans = (ans + (((pwr * pw(n - c + 1, 1000000007 - 2)) % 1000000007) * a[i]) %
                     1000000007) %
          1000000007;
  }
  cout << ans << endl;
  return 0;
}
