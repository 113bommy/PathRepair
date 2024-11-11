#include <bits/stdc++.h>
using namespace std;
int ar[111111];
int main() {
  int n, m, ans, i;
  cin >> n;
  cin >> m;
  for (i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  for (ans = 0, i = n - 1; i >= 0; ans++, i--) {
    m -= ar[i];
    if (m <= 0) break;
  }
  cout << ans;
}
