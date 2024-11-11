#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int MOD = 100000000;
int a, x, y;
int main() {
  cin >> a >> x >> y;
  if (y <= 0) {
    puts("-1");
    return 0;
  } else {
    int t = y / a;
    if ((t == 0 || (t & 1)) && abs(x) * 2 >= a) {
      puts("-1");
      return 0;
    }
    if ((t && t % 2 == 0) && (abs(x) >= a || abs(x) == 0)) {
      puts("-1");
      return 0;
    }
    if (y % a == 0) {
      puts("-1");
      return 0;
    }
    int ans = 1 + t / 2 * 3;
    if (t & 1)
      ans++;
    else if (x < 0)
      ans--;
    cout << ans << endl;
  }
  return 0;
}
