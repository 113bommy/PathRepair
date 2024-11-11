#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int a[n];
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = a[0];
    for (int i = 1; i < n; i++) {
      int inc = d / i;
      inc = min(inc, a[0]);
      ans += inc;
      d -= (inc * i);
      if (d < i) break;
    }
    cout << ans << endl;
  }
  return 0;
}
