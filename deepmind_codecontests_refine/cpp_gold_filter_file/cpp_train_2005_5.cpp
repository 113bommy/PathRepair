#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans.push_back(i + 1);
        ans.push_back(1);
        ans.push_back(1 + i);
      }
    }
    cout << ans.size() << " ";
    for (auto i : ans) cout << i << " ";
    cout << endl;
  }
  return 0;
}
