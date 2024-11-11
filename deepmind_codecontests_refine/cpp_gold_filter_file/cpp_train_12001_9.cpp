#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    unsigned long long sol = 0;
    bool x = false;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    sort(a.begin(), a.end());
    if (a[n - 1] > k)
      sol = 0;
    else {
      for (int i = 1; i < n; i++) {
        sol += int((k - a[i]) / a[0]);
        a[i] += int((k - a[i]) / a[0]) * a[0];
      }
      sort(a.begin(), a.end());
      sol += int((k - a[0]) / a[1]);
    }
    cout << sol << endl;
  }
  return 0;
}
