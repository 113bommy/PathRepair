#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c;
    d = (a + b + c) / 3;
    int ans = min(a, b);
    ans = min(d, ans);
    cout << ans;
  }
  return 0;
}
