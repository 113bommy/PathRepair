#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int c, b, e;
    cin >> c >> b >> e;
    if (c == 0) {
      int ans = 1000000001;
      for (int j = b; j < e; j++) {
        ans = min(ans, v.at(j));
      }
      cout << ans << endl;
    }
    if (c == 1) {
      int ans = -1000000001;
      for (int j = b; j < e; j++) {
        ans = max(ans, v.at(j));
      }
      cout << ans << endl;
    }
  }
}
