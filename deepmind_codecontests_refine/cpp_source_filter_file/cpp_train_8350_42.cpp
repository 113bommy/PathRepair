#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, m, ans;
    cin >> h;
    cin >> m;
    ans = (24 - h) * 60 + 60 - m;
    cout << ans << "\n";
  }
  return 0;
}
