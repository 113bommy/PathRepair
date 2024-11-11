#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (k == 1 && a[0] != a[n - 1]) {
      cout << -1 << endl;
      continue;
    }
    long long cnt = 1, ans = 1;
    for (long long i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) continue;
      cnt++;
      if (cnt > k) {
        cnt = 1;
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
