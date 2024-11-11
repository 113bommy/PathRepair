#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i == 0 || i == n - 1 || (a[i] > a[i - 1] && a[i] > a[i + 1])) {
        ans.push_back(a[i]);
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
