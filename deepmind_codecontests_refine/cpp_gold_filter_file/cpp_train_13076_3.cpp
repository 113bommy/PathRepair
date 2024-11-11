#include <bits/stdc++.h>
using namespace std;
string s[1005];
int main() {
  int n, ans = 0, tem = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 7; i++) {
    tem = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') tem++;
    }
    if (tem > ans) ans = tem;
  }
  cout << ans;
  return 0;
}
