#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[10010];
int mn = 100100;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i & 1) mn = min(mn, a[i]);
  }
  if (n % 2 == 0) {
    cout << 0 << "\n";
    return 0;
  }
  long long ans = (m / ((n + 1) / 2)) * k;
  ans = min(ans, 1ll * mn);
  cout << ans << endl;
  return 0;
}
