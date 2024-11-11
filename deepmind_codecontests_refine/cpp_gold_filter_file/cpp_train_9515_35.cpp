#include <bits/stdc++.h>
using namespace std;
int n, a[101], ps[101], ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = a[i] + ps[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      ans = max(ans, ps[n] + j - i + 1 - 2 * (ps[j] - ps[i - 1]));
    }
  }
  cout << ans << '\n';
  return 0;
}
