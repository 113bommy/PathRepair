#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 2147483647;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    if (i % m == 0 && 2 * i >= n) ans = min(ans, i);
  }
  if (ans == 2147483647)
    cout << "-1" << endl;
  else
    cout << ans << endl;
}
