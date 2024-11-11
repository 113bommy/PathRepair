#include <bits/stdc++.h>
using namespace std;
long n, a[1000], i, ans, x;
int main() {
  cin >> n >> x;
  ans = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 2; i <= n; i++) ans = max(ans, a[i - 1] - a[i] - x);
  cout << ans;
  return 0;
}
