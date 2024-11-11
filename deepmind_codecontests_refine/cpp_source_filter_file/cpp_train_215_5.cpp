#include <bits/stdc++.h>
using namespace std;
long long ans, n, a[2000020], s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (a[n / 2 + 1] == s) {
    cout << 0;
    return 0;
  }
  if (s > a[n / 2 + 1]) {
    for (long long i = n / 2 + 1; i <= n; i++)
      if (s > a[i]) ans += s - a[i];
  } else
    for (long long i = n / 2 + 1; i >= 1; i--)
      if (a[i] < s) ans += s - a[i];
  cout << ans;
  return 0;
}
