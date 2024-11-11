#include <bits/stdc++.h>
using namespace std;
void pre() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  pre();
  {
    long long int n;
    cin >> n;
    long long int a[n], mx = 0, ind = -1;
    for (long long int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << a[0];
      return 0;
    }
    long long int pref[n], suff[n];
    pref[0] = ~a[0];
    suff[n - 1] = ~a[n - 1];
    for (long long int i = 1; i < n; i++) pref[i] = pref[i - 1] & (~a[i]);
    for (long long int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] & (~a[i]);
    long long int as = -1, vl = 0;
    for (long long int i = 0; i < n; i++) {
      if (i == 0) {
        if (as <= (suff[i + 1] & a[i])) {
          as = suff[i + 1] & a[i];
          vl = a[i];
        }
      } else if (i == n - 1) {
        if (as <= (pref[i - 1] & a[i])) {
          as = pref[i - 1] & a[i];
          vl = a[i];
        }
      } else {
        if (as <= ((pref[i - 1] & suff[i + 1]) & a[i])) {
          as = ((pref[i - 1] & suff[i + 1]) & a[i]);
          vl = a[i];
        }
      }
    }
    bool gg = true;
    cout << vl << " ";
    for (long long int i = 0; i < n; i++) {
      if (a[i] == vl && gg)
        gg = false;
      else
        cout << a[i] << " ";
    }
  }
  return 0;
}
