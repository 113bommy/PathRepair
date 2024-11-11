#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n == 1) {
    int q;
    cin >> q;
    while (q--) {
      long long int x, y;
      cin >> x >> y;
      cout << y - x + 1 << " ";
    }
  } else {
    long long int k = a[n - 1] - a[0] + 1;
    vector<long long int> d;
    for (int i = 0; i < n - 1; i++) {
      d.push_back(a[i + 1] - a[i] - 1);
    }
    sort(d.begin(), d.end());
    vector<long long int> pre(n - 1);
    pre[0] = d[0];
    for (int i = 1; i < n - 1; i++) {
      pre[i] = pre[i - 1] + d[i];
    }
    long long int ans = k - pre[n - 2];
    int q;
    cin >> q;
    while (q--) {
      long long int x, y;
      cin >> x >> y;
      long long int num = y - x;
      long long int ind = lower_bound(d.begin(), d.end(), num) - d.begin();
      ind--;
      if (ind < 0)
        cout << ans + (n)*num << " ";
      else {
        long long int res = ans + pre[ind] + (n - ind - 1) * num;
        cout << res << " ";
      }
    }
  }
  return 0;
}
