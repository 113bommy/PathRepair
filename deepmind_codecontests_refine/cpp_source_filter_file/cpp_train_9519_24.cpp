#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, n, m, k, ans;
  while (cin >> c >> d) {
    cin >> n >> m >> k;
    int s = n * m - k;
    if (s <= 0)
      ans = 0;
    else {
      if (n * d >= c) {
        int s1 = s - s / n * n;
        if (s == 0)
          ans = s / n * c;
        else if (s1 * d < c)
          ans = s / n * c + s1 * d;
        else
          ans = s / n * c + 1;
      } else
        ans = s * d;
    }
    cout << ans << endl;
  }
  return 0;
}
