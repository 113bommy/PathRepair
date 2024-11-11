#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int a[3] = {x, x, x};
  int ans = 0;
  while (a[0] < y) {
    a[0] = min(y, a[1] + a[2] - 1);
    sort(a, a + 3);
    ans++;
  }
  cout << ans << endl;
}
