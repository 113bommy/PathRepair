#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0, x = 0, ans1 = INT_MAX;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
      int in1 = 0;
      cin >> in1;
      if (!(x % in1))
        ans1 = min(ans1, x / in1);
      else
        ans1 = min(ans1, max(2, (x - 1) / in1 + 1));
    }
    cout << ans1 << endl;
  }
  return 0;
}
