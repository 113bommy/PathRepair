#include <bits/stdc++.h>
using namespace std;
const int N = 101;
map<int, int> mp;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    mp.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 200; i++) {
      int tot = 0;
      for (int j = 1; j <= i / 2; j++) {
        if (i - j != j) {
          tot += min(mp[i - j], mp[j]);
        } else {
          tot += mp[j] / 2;
        }
      }
      ans = max(ans, tot);
    }
    cout << ans << endl;
  }
}
