#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
int l, r, n, a[MN], ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    a[l - r + 3000]++;
    a[l + r]++;
  }
  for (int i = 0; i <= 3000; i++) {
    if (a[i]) {
      ans += (a[i] * (a[i] - 1) / 2);
    }
  }
  cout << ans << endl;
  return 0;
}
