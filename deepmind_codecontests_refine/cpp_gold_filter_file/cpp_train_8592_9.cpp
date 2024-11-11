#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, r;
    cin >> n >> r;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
    }
    sum %= n;
    r--;
    int ans = r - sum;
    if (ans <= 0) ans += n;
    cout << ans << "\n";
  }
  return 0;
}
