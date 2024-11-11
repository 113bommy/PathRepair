#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int x = n[0] - 1;
    int ans = (1 + 2 + 3 + 4) * x;
    for (int i = 1; i <= n.size(); i++) {
      ans += i;
    }
    cout << ans << "\n";
  }
  return 0;
}
