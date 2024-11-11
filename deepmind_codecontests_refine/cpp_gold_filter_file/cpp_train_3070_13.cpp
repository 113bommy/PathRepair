#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  string str1, str2;
  cin >> str1 >> str2;
  int n = str2.length();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str1[i] != str2[i]) cnt++;
  }
  if (cnt % 2 == 1) {
    cout << "impossible" << '\n';
    return 0;
  }
  string str3 = "";
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (str1[i] == str2[i])
      str3 += str1[i];
    else {
      if (!flag) {
        str3 += str1[i];
        flag = 1;
      } else {
        str3 += str2[i];
        flag = 0;
      }
    }
  }
  cout << str3 << '\n';
}
