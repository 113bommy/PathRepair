#include <bits/stdc++.h>
using namespace std;
int flag;
int n, m, len;
long long a[200005];
long long ans, temp;
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n) {
    for (int i = 0; i < 2 * n; ++i) cin >> a[i];
    sort(a, a + n + n);
    ans = (a[2 * n - 1] - a[n]) * (a[n - 1] - a[0]);
    temp = a[2 * n - 1] - a[0];
    for (int i = 1; i < n; ++i) {
      ans = min(ans, temp * (a[i + n - 1] - a[i]));
    }
    cout << ans << endl;
  }
  return 0;
}
