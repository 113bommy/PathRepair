#include <bits/stdc++.h>
using namespace std;
string fixCaps(string str) {
  string res;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] >= 65 && str[i] <= 90) {
      res += (char)(str[i] + 32);
    } else {
      return str;
    }
  }
  if (str[0] >= 65 && str[0] <= 90) {
    res = (char)(str[0]) + res;
  } else {
    res = (char)(str[0] - 32) + res;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  cout << fixCaps(str) << endl;
  return 0;
}
