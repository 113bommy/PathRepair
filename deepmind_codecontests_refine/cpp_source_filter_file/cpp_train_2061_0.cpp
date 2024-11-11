#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool flag = true;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if ((i % 2 == 1 && s[i] == 'L') || (i % 2 == 0 && s[i] == 'R'))
      flag = false;
  }
  cout << (flag ? "Yes" : "No") << endl;
}
