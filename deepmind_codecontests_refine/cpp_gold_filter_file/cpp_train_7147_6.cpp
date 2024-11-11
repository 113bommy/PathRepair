#include <bits/stdc++.h>
using namespace std;
int a[100000];
long long psum[100000];
int t[100000];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!t[i]) {
      psum[i] = a[i];
    } else
      ans += a[i];
    if (i > 0) psum[i] += psum[i - 1];
  }
  long long ans2 = 0;
  for (int i = 0; i <= n - k; i++) {
    if (i == 0)
      ans2 = max(ans2, psum[i + k - 1]);
    else
      ans2 = max(ans2, psum[i + k - 1] - psum[i - 1]);
  }
  cout << ans2 + ans;
  return 0;
}
