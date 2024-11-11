#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  ll arr[n + 1];
  int i;
  ll sum = 0;
  for (i = 1; i <= (n + 1) / 2; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  ll x;
  cin >> x;
  for (i = (n + 1) / 2 + 1; i <= n; i++) {
    arr[i] = x;
    sum += arr[i];
  }
  if (sum > 0) {
    cout << n << '\n';
    return 0;
  } else {
    if (x >= 0) {
      cout << -1 << '\n';
      return 0;
    } else {
      ll pref[n + 1];
      pref[0] = 0;
      int i;
      for (i = 1; i <= n; i++) pref[i] = pref[i - 1] + arr[i];
      ll maxa = -1e9;
      bool ok = 0;
      for (i = 0; i <= (n / 2); i++) {
        maxa = max(maxa, pref[i] + x * (n - i));
        if (maxa < pref[n] + x * (n - i)) {
          ok = 1;
          break;
        }
      }
      if (!ok)
        cout << -1 << '\n';
      else
        cout << (n - i) << '\n';
    }
  }
}
