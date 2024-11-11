#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
bool judge(long double x, long double y, long double k) {
  return sqrt(x * x + y * y) - eps <= k;
}
long long getAns(int k) {
  long double sq3 = sqrt(3);
  long double x, y;
  long long ans = 0;
  int cnt = 0;
  for (y = 0; true; y += sq3) {
    if (judge(0.5, y + sq3 / 2, k))
      cnt++;
    else {
      y -= sq3;
      break;
    }
  }
  cnt = cnt * 2 - 1;
  ans += cnt;
  x = 0;
  while (true) {
    y += sq3 / 2;
    x += 1.5;
    cnt++;
    if (y + eps < 0) break;
    while ((!judge(x + 0.5, y + sq3 / 2, k) || !judge(x + 1, y, k)) &&
           y + eps >= 0)
      y -= sq3, cnt -= 2;
    if (cnt > 0) ans += cnt * 2;
  }
  return ans;
}
int main() {
  int k;
  while (cin >> k) cout << getAns(k) << endl;
  return 0;
}
