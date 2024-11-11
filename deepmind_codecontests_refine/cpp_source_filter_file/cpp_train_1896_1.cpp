#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string ans[t];
  int i, a;
  for (i = 0; i < t; i++) {
    cin >> a;
    if (a > 14) {
      if (a % 14 < 7 && a % 14 > 0) {
        ans[i] = "YES";
      } else
        ans[i] = "NO";
    } else
      ans[i] = "NO";
  }
  for (i = 0; i < t; i++) cout << ans[i] << endl;
  return 0;
}
