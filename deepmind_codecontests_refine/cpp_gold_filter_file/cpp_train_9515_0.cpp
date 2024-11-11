#include <bits/stdc++.h>
using namespace std;
long long t, i, j, k;
int a[105], pref1[105] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    for (i = 0; i < n; ++i) cin >> a[i];
    for (i = 1; i < n + 1; ++i) pref1[i] = pref1[i - 1] + (a[i - 1] == 1);
    int ans = 0;
    for (i = 1; i < n + 1; ++i) {
      for (j = n; j >= i; --j) {
        int _1s = pref1[j] - pref1[i - 1];
        int _0s = (j - i + 1) - _1s;
        int _1sBFRi = pref1[i - 1];
        int _1sAFRj = pref1[n] - pref1[j];
        ans = max(ans, _0s + _1sBFRi + _1sAFRj);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
