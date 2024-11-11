#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<bool> v(202);
    fill(v.begin(), v.end(), false);
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      v[a] = true;
    }
    int ans = 0;
    for (int i = 1; i < 202; i++) {
      if (v[i - 1] == true && v[i] == false && x == 0) {
        ans = i - 1;
      }
      if (v[i] == false) {
        v[i] = true;
        x--;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
