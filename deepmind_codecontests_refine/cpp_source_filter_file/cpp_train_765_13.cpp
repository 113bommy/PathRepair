#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s[t];
  string rstring = "";
  for (int i = 0; i < t; i++) {
    cin >> s[i];
    rstring += "." + s[i];
  }
  for (char i = 'a'; i <= 'z'; i++) {
    if (rstring.find(i) == string::npos) {
      cout << i;
      break;
    }
  }
  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      string temp;
      temp = i;
      temp += j;
      if (rstring.find(temp) == string::npos) {
        cout << temp;
        return 0;
      }
    }
  }
}
