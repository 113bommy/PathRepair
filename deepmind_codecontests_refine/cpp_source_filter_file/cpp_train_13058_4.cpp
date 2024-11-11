#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, c, ans = 0, sum = 0;
  cin >> n >> c >> t;
  while (n--) {
    int x;
    cin >> x;
    if (x > t)
      sum = 0;
    else {
      sum++;
      if (sum >= c) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
