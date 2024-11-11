#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> arr(250);
    map<int, int> mp;
    for (int i = 0; i < 250; i++) {
      cin >> arr[i];
      mp[arr[i]]++;
    }
    double mean = 0.0, var = 0.0;
    for (auto it : mp) {
      mean += (it.first * it.second / 250.0);
    }
    for (auto it : mp) {
      var += (it.first - mean) * (it.first - mean) * (it.second / 250.0);
    }
    if ((var / mean) < 10)
      cout << "poisson\n";
    else
      cout << "uniform\n";
  }
  return 0;
}
