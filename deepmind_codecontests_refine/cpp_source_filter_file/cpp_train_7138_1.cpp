#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int len = 20000;
  string di;
  int mo;
  string ans[2] = {"NO", "YES"};
  bool yes = 1;
  for (int i = 0; i < n; ++i) {
    cin >> mo >> di;
    if (i == 0 && di != "South") yes = 0;
    if (len == 0 && di != "North") yes = 0;
    if (len > 20000 || len < 0) yes = 0;
    if (di == "South") len -= mo;
    if (di == "North") len += mo;
  }
  yes = (len == 20000) && yes;
  cout << ans[yes];
  return 0;
}
