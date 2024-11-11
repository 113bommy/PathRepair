#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, ans, a[N];
int main() {
  int k;
  cin >> k;
  while (k--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, min(i, a[i]));
    cout << ans << endl;
  }
  return 0;
}
