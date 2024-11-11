#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  cin >> a[0];
  long long maxn = a[0], minn = a[0];
  for (long long i = 1; i < n; i++) {
    cin >> a[i];
    maxn = max(maxn, a[i]);
    minn = min(minn, a[i]);
  }
  if (k == 1) {
    cout << minn;
  } else if (k == 2) {
    vector<long long> pref(n);
    pref[0] = a[0];
    for (long long i = 1; i < n; i++) {
      pref[i] = min(pref[i - 1], a[i]);
    }
    vector<long long> suf(n);
    suf[n - 1] = a[n - 1];
    for (long long i = n - 2; i >= 0; i--) {
      suf[i] = min(suf[i + 1], a[i]);
    }
    long long ans = -2e9;
    for (long long i = 0; i < n - 1; i++) {
      long long m1 = pref[i];
      long long m2 = suf[i + 1];
      ans = max(ans, max(m1, m2));
    }
    cout << ans;
  } else {
    cout << maxn;
  }
  return 0;
}
