#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ans += y - x + 1;
  }
  int res1;
  if (ans % 7 != 0)
    res1 = k * ((ans / k) + 1) - ans;
  else
    res1 = 0;
  cout << res1 << endl;
  return 0;
}
