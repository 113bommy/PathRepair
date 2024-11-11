#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  string ans;
  for (auto c : str) {
    switch (c) {
      case '2':
        ans += '2';
        break;
      case '3':
        ans += '3';
        break;
      case '4':
        ans += "322";
        break;
      case '5':
        ans += '5';
        break;
      case '6':
        ans += "5222";
        break;
      case '7':
        ans += '7';
        break;
      case '8':
        ans += "7222";
        break;
      case '9':
        ans += '9';
        break;
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
