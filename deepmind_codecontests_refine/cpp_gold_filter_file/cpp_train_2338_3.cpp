#include <bits/stdc++.h>
const long long MXN = 3e6 + 1;
const long long MNN = 1e3 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;
using namespace std;
long long n, a[MXN], cnt[MXN], sum, s, ans;
int main() {
  ios_base::sync_with_stdio, cout.tie(0), cin.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3 != 0) {
    cout << 0 << endl;
    return 0;
  } else {
    sum = sum / 3;
    for (int i = n; i >= 1; i--) {
      s += a[i];
      if (s == sum) {
        cnt[i] = 1;
      }
    }
    for (int i = n - 1; i >= 1; --i) {
      cnt[i] += cnt[i + 1];
    }
    s = 0;
    for (int i = 1; i <= n - 2; ++i) {
      s += a[i];
      if (s == sum) ans += cnt[i + 2];
    }
  }
  cout << ans;
  return 0;
}
