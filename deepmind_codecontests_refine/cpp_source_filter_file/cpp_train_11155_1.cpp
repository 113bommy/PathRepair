#include <bits/stdc++.h>
using namespace std;
long long a[110];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i] + a[i + 1] == 5) return (cout << "Infinite" << endl, 0);
    ans += max(a[i], a[i - 1]) + 1;
    if (i >= 2 && a[i] == 2 && a[i - 2] == 3) ans--;
  }
  cout << "Finite\n" << ans << endl;
  return 0;
}
