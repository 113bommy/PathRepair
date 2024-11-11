#include <bits/stdc++.h>
using namespace std;
long long int gc(long long int a, long long int b) {
  return (b > 0) ? gc(b, a % b) : a;
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = -1, sum = 0;
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      long long int input;
      cin >> input;
      if (input > k)
        continue;
      else if (input >= (k + 1) / 2) {
        ans = i + 1;
      } else if (sum + input <= k) {
        sum = sum + input;
        v.push_back(i + 1);
      }
    }
    if (ans != -1) {
      cout << "1"
           << "\n";
      cout << ans;
    } else {
      if (sum <= k && sum >= (k + 1) / 2) {
        cout << v.size() << "\n";
        for (auto i : v) cout << i << " ";
      } else {
        cout << -1;
      }
    }
    cout << "\n";
  }
  return 0;
}
