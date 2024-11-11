#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    pair<long long, long long> a[n];
    bool h = false;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
      if (a[i].first <= k && a[i].first >= (k + 1) / 2) {
        h = true;
        ans = i;
      }
    }
    if (h == true) {
      cout << 1 << '\n';
      cout << ans + 1 << '\n';
    } else {
      sort(a, a + n);
      long long sm = 0;
      int i = 0;
      while (i < n && sm < k / 2) {
        sm += a[i].first;
        i++;
      }
      if (sm > k || sm < (k + 1) / 2) {
        cout << -1 << '\n';
      } else {
        cout << i << '\n';
        for (int j = 0; j < i; j++) {
          cout << a[j].second + 1 << " ";
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
