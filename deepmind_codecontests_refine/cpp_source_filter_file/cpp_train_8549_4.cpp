#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int flag(0), count(0);
  while (s.length() != 0) {
    flag = 0;
    for (int i = 1; i < s.length(); i++) {
      if (s[i - 1] == s[i]) {
        s.erase(i - 1, i + 1);
        count++;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      break;
    }
  }
  if (count % 2 == 0) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  return 0;
}
