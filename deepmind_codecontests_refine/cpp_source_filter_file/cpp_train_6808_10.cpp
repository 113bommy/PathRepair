#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string r = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') r += '0';
    if (s[i] == '-') {
      if (s[i + 1] == '-')
        r += '2';
      else
        r += '1';
      i++;
    }
    cout << r << endl;
  }
}
