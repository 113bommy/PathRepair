#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int a[n + 1], i, j, ans = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i < n; i++) {
    for (j = 0; i + (1 << j) <= n; j++) {
    }
    a[i + (1 << j)] += a[i];
    ans += a[i];
    cout << ans << endl;
  }
  return 0;
}
