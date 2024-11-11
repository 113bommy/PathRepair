#include <bits/stdc++.h>
using namespace std;
int arr[200004];
long long int pref[200004], suf[200004];
int main() {
  long long int i, n, k;
  cin >> n >> k;
  for (i = 0; i <= n; i++) cin >> arr[i];
  for (i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + arr[i];
    if (pref[i + 1] % 2) {
      for (int j = i + 1; j <= n; j++) pref[j] = 1e16 + 5;
      break;
    } else
      pref[i + 1] /= 2;
  }
  for (i = n; i > 0; i--) {
    suf[i - 1] = suf[i] + arr[i];
    suf[i - 1] *= 2;
    if (abs(suf[i - 1]) >= 1e16 + 5) {
      for (int j = i - 1; j >= 0; j--) suf[i - 1] = 1e16 + 5;
      break;
    }
  }
  long long int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (pref[i] != 1e16 + 5 && suf[i] != 1e16 + 5) {
      long long int maybe = ((long long int)-1 * (pref[i] + suf[i]));
      if (i == n && maybe == 0) continue;
      if (abs(maybe) <= k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
