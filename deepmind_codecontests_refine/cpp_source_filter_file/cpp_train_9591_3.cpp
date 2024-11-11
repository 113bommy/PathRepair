#include <bits/stdc++.h>
using namespace std;
long long ans, n, k, a[1010], sum;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  for (int i = 0; i < n - k; i++) {
    long long tmp = sum;
    for (int j = i; j < n; j += k) tmp -= a[j];
    ans = max(ans, abs(tmp));
  }
  cout << ans << '\n';
  return 0;
}
