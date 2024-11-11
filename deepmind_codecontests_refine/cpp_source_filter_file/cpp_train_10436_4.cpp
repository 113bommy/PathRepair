#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      vec.push_back(v);
    }
    sort(vec.begin(), vec.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      cnt++;
      if (cnt == vec[i]) {
        ans += cnt;
        cnt = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
