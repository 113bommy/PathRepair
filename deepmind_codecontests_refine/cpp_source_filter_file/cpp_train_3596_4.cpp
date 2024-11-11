#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x, ans = 0;
  cin >> n >> x;
  char c;
  int count;
  while (n--) {
    cin >> c >> count;
    if (c == '+')
      x += count;
    else if (x >= count)
      x -= count;
    else
      ++ans;
  }
  cout << x << ' ' << ans << endl;
  return 0;
}
