#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long one, two;
  cin >> n;
  one = two = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x == 1)
      one++;
    else
      two++;
  }
  int ans, flag = 0;
  if (!two)
    cout << one / 3 << endl;
  else if (!one)
    cout << 0 << endl;
  else {
    int mx = min(one, two);
    one -= mx;
    ans = mx + ((one >= 3) ? one / 3 : 0);
    flag = 1;
  }
  if (flag) cout << ans << endl;
  return 0;
}
