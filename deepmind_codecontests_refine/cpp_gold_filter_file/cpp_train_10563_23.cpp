#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
int main() {
  int n, m;
  cin >> n >> m;
  string str1, str2;
  while (m--) {
    cin >> str1 >> str2;
    if (str1.length() > str2.length()) {
      mp[str1] = str2;
      mp[str2] = str2;
    } else {
      mp[str1] = str1;
      mp[str2] = str1;
    }
  }
  while (n--) {
    cin >> str1;
    cout << mp[str1] << " ";
  }
  return 0;
}
