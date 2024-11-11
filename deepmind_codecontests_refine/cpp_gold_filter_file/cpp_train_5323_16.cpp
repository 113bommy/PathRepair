#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int s = 0, f = 0, flag = 0;
  if (n % 4 == 0) {
    f = n / 4;
  } else {
    while (n % 4 != 0 && n >= 7) {
      n -= 7;
      s += 1;
    }
    if (n % 4 != 0) {
      cout << -1;
      flag = 1;
    } else
      f = n / 4;
  }
  if (!flag) {
    string ans = "";
    s += (4 * (f / 7));
    f = (f % 7);
    for (long long int i = 0; i < f; i++) ans += "4";
    for (long long int i = 0; i < s; i++) ans += "7";
    cout << ans;
  }
  return 0;
}
