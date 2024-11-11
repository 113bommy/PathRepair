#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  int a[1010], b[1010];
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int s = a[i];
      while (s <= ans) s += b[i];
      ans = s;
    }
    cout << ans << endl;
  }
  return 0;
}
