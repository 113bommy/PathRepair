#include <bits/stdc++.h>
using namespace std;
const int MX = 2009, inf = (1 << 20);
int main() {
  string str;
  cin >> str;
  for (int j = 0; j < str.size(); j++) {
    if (str[j] != 'a') {
      for (int i = j; i < str.size(); i++) {
        if (str[i] != 'a')
          str[i]--;
        else
          break;
      }
      cout << str << endl;
      return 0;
    }
  }
  str[str.size() - 1] = 'z';
  cout << str << endl;
}
