#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], l[n + 1], r[n + 1], sum = 0;
  l[0] = 0;
  r[n] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    l[i + 1] = l[i] - 2 * a[i];
    sum += a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    r[i] = r[i + 1] - 2 * a[i];
  }
  for (int i = 1; i < n; i++) {
    l[i] = max(l[i], l[i - 1]);
    r[n - i - 1] = max(r[n - i], r[n - i - 1]);
  }
  int ans = max(sum, -sum);
  for (int i = 0; i < n; i++) {
    ans = max(ans, sum + l[i] + r[i]);
  }
  cout << ans << endl;
  return 0;
}
