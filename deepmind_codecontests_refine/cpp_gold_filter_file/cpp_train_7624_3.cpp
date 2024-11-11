#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int min_v = min(a, b);
    int max_v = max(a, b);
    int ans = max(max_v, min_v * 2);
    cout << ans * ans << endl;
  }
  return 0;
}
