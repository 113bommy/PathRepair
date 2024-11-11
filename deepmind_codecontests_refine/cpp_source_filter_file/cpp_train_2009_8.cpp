#include <bits/stdc++.h>
using namespace std;
const int INF = ~(1 << 31);
const double EPS = 0.0000001;
int main() {
  int a4, a7, a47, a74, x4, x7;
  cin >> a4 >> a7 >> a47 >> a74;
  if (abs(a47 - a74) > 1) {
    cout << -1 << endl;
    return 0;
  }
  string ans = "";
  if (a47 == a74) {
    if (a4 == 1) {
      for (int i = 0; i < a47; i++) ans += "74";
      ans += "7";
      x4 = a47;
      x7 = a47 + 1;
    } else {
      for (int i = 0; i < a47; i++) ans += "47";
      ans += "4";
      x4 = a47 + 1;
      x7 = a47;
    }
  } else if (a47 < a74) {
    for (int i = 0; i < a74; i++) ans += "74";
    x4 = a74;
    x7 = a74;
  } else {
    for (int i = 0; i < a47; i++) ans += "47";
    x4 = a47;
    x7 = a47;
  }
  if (a4 < x4 || a7 < x7) {
    cout << -1 << endl;
    return 0;
  }
  bool b = 0;
  if (ans[0] == '7') {
    cout << 7;
    ans.erase(0, 1);
  }
  for (int i = 0; i < a4 - x4; i++) cout << 4;
  if (ans[ans.size() - 1] == '4') {
    b = 1;
    ans.erase(ans.size() - 1, 1);
  }
  cout << ans;
  for (int i = 0; i < a7 - x7; i++) cout << 7;
  if (b) cout << 4 << endl;
  return 0;
}
