#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, y, low = 0, up = 0;
  char c;
  cin >> n;
  while (n--) {
    cin >> c >> x >> y;
    if (x > y) swap(x, y);
    if (c == '+') {
      low = max(low, x);
      up = max(up, y);
    } else {
      if (low <= x && up <= y)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
