#include <bits/stdc++.h>
using namespace std;
unsigned long long a[100005];
int main() {
  int n, k, count = 0, ans[100005], i;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
  if (a[n] % k != 0) {
    cout << "No";
    return 0;
  }
  unsigned long long s = a[n] / k;
  for (i = 0; i < n;) {
    unsigned long long t = lower_bound(a + i, a + n + 1, a[i] + s) - a;
    if (a[t] != a[i] + s) {
      cout << -1;
      return 0;
    }
    ans[count++] = t - i;
    i += t - i;
  }
  cout << "Yes\n";
  for (i = 0; i < k; i++) cout << ans[i] << " ";
  return 0;
}
