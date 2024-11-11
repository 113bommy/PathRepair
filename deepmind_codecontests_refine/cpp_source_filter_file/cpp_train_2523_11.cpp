#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;
    if (x == 0 && y == 0) {
      cout << "0\n";
    } else if (x == 0 || y == 0) {
      if (x == 0)
        cout << a * x << "\n";
      else
        cout << a * y << "\n";
    } else {
      int mini = INT_MAX;
      int maxi = INT_MIN;
      if (x < y) {
        mini = x;
        maxi = y;
      } else {
        mini = y;
        maxi = x;
      }
      long long int ans;
      if ((mini * b) < (mini * 2 * a)) {
        ans = mini * b;
      } else {
        ans = mini * 2 * a;
      }
      maxi = maxi - mini;
      ans += (maxi * a);
      cout << ans << "\n";
    }
  }
  return 0;
}
