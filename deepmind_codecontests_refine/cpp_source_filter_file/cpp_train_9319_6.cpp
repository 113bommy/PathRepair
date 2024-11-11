#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1111], b[1111];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long cur1 = 0, cur2 = 0;
    for (int j = i; j <= n; ++j) {
      cur1 = cur1 or a[j];
      cur2 = cur2 or b[j];
      ans = max(ans, cur1 + cur2);
    }
  }
  cout << ans;
  return 0;
}
