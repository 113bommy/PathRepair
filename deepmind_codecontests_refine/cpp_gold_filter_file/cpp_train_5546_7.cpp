#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long int pl = 0, mn = 0, ze = 0, ans = 0, ma = -1000000000000000000;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0)
        pl++;
      else if (a[i] < 0)
        mn++;
      else
        ze++;
    }
    if (mn == n) {
      cout << a[n - 1] * a[n - 4] * a[n - 5] * a[n - 3] * a[n - 2] << "\n";
      goto label;
    }
    if (ze > n - 5) {
      cout << 0 << "\n";
      goto label;
    }
    ans = a[n - 1] * a[0] * a[1] * a[2] * a[3];
    ma = max(ma, ans);
    ans = a[n - 1] * a[0] * a[1] * a[n - 3] * a[n - 2];
    ma = max(ma, ans);
    ans = a[n - 1] * a[n - 4] * a[n - 5] * a[n - 3] * a[n - 2];
    ma = max(ma, ans);
    cout << ma << "\n";
  label:;
  }
}
