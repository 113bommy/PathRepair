#include <bits/stdc++.h>
using namespace std;
long long n, a[100002];
long long ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ans = (n * (n - 1) / 2 + n) * n;
  for (int i = 2; i <= n; i++)
    ans -= min(a[i], a[i - 1]) * (n - max(a[i], a[i - 1]) + 1);
  for (int i = 1; i <= n; i++)
    ans -= n * (n - 1) / 2 + n - a[i] * (n - a[i] + 1);
  cout << ans << "\n";
  return 0;
}
