#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, d, ans1, ans2, ans3;
  cin >> t;
  while (t--) {
    ans1 = 0;
    ans2 = 0;
    ans3 = 0;
    cin >> a >> b >> c >> d;
    ans1 = a / b;
    ans2 = (a - 1) / b;
    ans3 = d / b;
    ans1 -= ans3;
    ans1 += ans2;
    cout << ans1 << endl;
  }
  return 0;
}
