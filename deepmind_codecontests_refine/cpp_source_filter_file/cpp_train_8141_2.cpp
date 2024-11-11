#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string second;
    cin >> second;
    vector<long long> ans;
    long long n = second.size();
    for (long long i = 0; i < n - 4; i++) {
      if (second.substr(i, 5) == "twone") {
        ans.push_back(i + 2);
        second[i + 2] = '$';
      }
    }
    for (long long i = 0; i < n - 2; i++) {
      if (second.substr(i, 3) == "one" || second.substr(i, 3) == "two") {
        ans.push_back(i + 1);
      }
    }
    cout << ans.size() << endl;
    for (auto u : ans) {
      cout << u << " ";
    }
    cout << endl;
  }
  return 0;
}
