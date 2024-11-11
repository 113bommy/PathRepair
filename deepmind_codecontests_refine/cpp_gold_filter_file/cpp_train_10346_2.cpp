#include <bits/stdc++.h>
using namespace std;
long long ans = -(1 << 30), n, f, t, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> f >> t;
    if (t >= k)
      ans = max(ans, f - (t - k));
    else
      ans = max(ans, f);
  }
  cout << ans;
}
