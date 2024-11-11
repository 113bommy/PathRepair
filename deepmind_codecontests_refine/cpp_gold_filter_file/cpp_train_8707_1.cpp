#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int* pref = new int[n + 1];
  int* suff = new int[n + 1];
  pref[0] = suff[n] = 0;
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + (a[i - 1] == 1);
    suff[n - i] = suff[n - i + 1] + (a[n - i] == 2);
  }
  int** dp1 = new int*[n];
  for (int i = 0; i < n; ++i) dp1[i] = new int[n];
  int** dp2 = new int*[n];
  for (int i = 0; i < n; ++i) dp2[i] = new int[n];
  for (int i = 0; i < n; ++i) {
    dp1[i][i] = (a[i] == 1);
    dp2[i][i] = dp1[i][i] ^ 1;
  }
  for (int l = 0; l < n; ++l) {
    for (int r = l + 1; r < n; ++r) {
      if (a[r] == 1) {
        dp1[l][r] = max(dp1[l][r - 1], dp2[l][r - 1]) + 1;
        dp2[l][r] = dp2[l][r - 1];
      } else {
        dp1[l][r] = dp1[l][r - 1];
        dp2[l][r] = dp2[l][r - 1] + 1;
      }
    }
  }
  int ans = max(pref[n], suff[0]);
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      ans = max(ans, pref[l] + suff[r + 1] + max(dp1[l][r], dp2[l][r]));
    }
  }
  cout << ans;
}
