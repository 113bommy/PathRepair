#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> v(n);
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
      cin >> vp[i].first;
      vp[i].second = i;
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n - 1; i++) {
      if (vp[i + 1].second - vp[i].second != 1) {
        ans++;
      }
    }
    if (ans <= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
