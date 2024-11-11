#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int ans = 0, mn = 1e9;
  int n;
  cin >> n;
  long long int a[n], dif[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    dif[i] = abs(a[i + 1] - a[i]);
    if (dif[i] < mn) mn = dif[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (dif[i] == mn) ans++;
  }
  cout << mn << ' ' << ans << '\n';
  return 0;
}
