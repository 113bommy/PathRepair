#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, q = 1000001, n, a[100001] = {0}, k, ans = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    if (b < q) q = b;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = n; i > 0; i--) {
    if (i >= q + 1) {
      i -= q;
      ans -= a[i];
      i--;
      ans -= a[i];
    } else
      break;
  }
  cout << ans;
}
