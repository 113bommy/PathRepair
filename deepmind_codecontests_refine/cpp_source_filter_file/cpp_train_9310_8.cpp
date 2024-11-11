#include <bits/stdc++.h>
using namespace std;
string s;
string t;
bool flag;
int main() {
  cin >> s;
  for (int i = 0; i < s.size();) {
    if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't' &&
        (i != 0 && i != s.size() - 2)) {
      t += '.';
      i += 3;
    } else if (s[i] == 'a' && s[i + 1] == 't' &&
               (i != 0 && i != s.size() - 1) && !flag) {
      t += '@';
      i += 2;
      flag = true;
    } else {
      t += s[i];
      i++;
    }
  }
  cout << t << endl;
  return 0;
}
