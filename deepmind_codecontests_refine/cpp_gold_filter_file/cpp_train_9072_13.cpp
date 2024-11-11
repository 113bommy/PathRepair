#include <bits/stdc++.h>
using namespace std;
const int maxx = 0x3f3f3f3f;
int main() {
  int n, ans = 0;
  cin >> n;
  ans = n / 2 + 1;
  cout << ans << endl;
  for (int i = 1; i <= ans; ++i) {
    cout << 1 << " " << i << endl;
  }
  for (int j = 2; j <= n - ans + 1; ++j) {
    cout << ans << " " << j << endl;
  }
  return 0;
}
