#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long n, m, k, a, b, Min = 1876543210, mid, ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (i % 2 == 1) Min = min(Min, a);
  }
  mid = (n + 1) / 2;
  if (mid <= m) ans = min(m / mid * k, Min);
  cout << ans;
}
