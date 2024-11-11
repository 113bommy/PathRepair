#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int ans = -999;
  for (int i = 0; i < n; i++) {
    int f, t;
    int fun = 0;
    cin >> f >> t;
    if (t > k) {
      fun = f - (t - k);
    } else {
      fun = f;
    }
    ans = max(ans, fun);
  }
  cout << ans;
}
