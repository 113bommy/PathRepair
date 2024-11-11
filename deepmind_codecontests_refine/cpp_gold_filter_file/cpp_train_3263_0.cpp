#include <bits/stdc++.h>
using namespace std;
long long a[10001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i;
  long long ans = 0;
  cin >> t;
  for (i = 0; i < t; i++) cin >> a[i];
  for (i = 0; i < t; i++) {
    if (a[i] % 2 == 0)
      ans = (a[i] << 2) + 1;
    else {
      if (a[i] % 4 == 1) ans = (a[i] << 1) + 1;
      if (a[i] % 4 == 3) ans = a[i] + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
