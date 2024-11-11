#include <bits/stdc++.h>
using namespace std;
int n, a[100005], sum, ans, ans2;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    ans2 = max(ans2 + a[i], 0);
    ans = max(ans, ans2);
  }
  cout << ans2 - (sum - ans);
  return 0;
}
