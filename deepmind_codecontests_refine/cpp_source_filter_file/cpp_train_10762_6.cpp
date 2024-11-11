#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long time = a[0], mx = b[0], ans = a[0];
  for (int i = 1; i < n; i++) {
    long long t = a[i] - time;
    long long mn = min(t, mx);
    time = a[i];
    mx = mx - mn;
    mx += b[i];
    ans = max(ans, mx);
  }
  cout << a[n - 1] + mx << " " << ans;
}
