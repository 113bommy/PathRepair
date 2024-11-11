#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  string ans;
  if (a3 == a4 + 1) {
    for (int i = 0; i < a1 - a3; i++) ans += '4';
    for (int i = 0; i < a3; i++) ans += "47";
    for (int i = 0; i < a2 - a3; i++) ans += '7';
  } else if (a3 == a4) {
    if (0 <= a1 - a3 - 1) {
      for (int i = 0; i < a1 - a3 - 1; i++) ans += '4';
      for (int i = 0; i < a3; i++) ans += "47";
      for (int i = 0; i < a2 - a3; i++) ans += '7';
      ans += '4';
    } else {
      ans = "7";
      for (int i = 0; i < a1 - a3; i++) ans += '4';
      for (int i = 0; i < a3; i++) ans += "47";
      for (int i = 0; i < a2 - a3 - 1; i++) ans += '7';
    }
  } else if (a3 == a4 - 1) {
    ans += "74";
    for (int i = 0; i < a1 - a4; i++) ans += '4';
    for (int i = 0; i < a4 - 2; i++) ans += "74";
    for (int i = 0; i < a2 - a4; i++) ans += '7';
    ans += "74";
  }
  int n = ans.size();
  for (int i = 0; i < n; i++) {
    if (ans[i] == '4') a1--;
    if (ans[i] == '7') a2--;
    if (i < n && ans[i] == '4' && ans[i + 1] == '7') a3--;
    if (i < n && ans[i] == '7' && ans[i + 1] == '4') a4--;
  }
  if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
