#include <bits/stdc++.h>
using namespace std;
int main() {
  long long deg, cur;
  int count, ans;
  cin >> deg;
  deg %= 360;
  if (deg < 0) deg += 360;
  if (deg <= 45 || deg >= 315)
    ans = 0;
  else if (deg >= 225)
    ans = 1;
  else if (deg >= 135)
    ans = 2;
  else
    ans = 3;
  cout << ans << endl;
  return 0;
}
