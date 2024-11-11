#include <bits/stdc++.h>
using namespace std;
int main() {
  int k = 0;
  string s, s1, s3 = "WUB", s4, s5 = " ";
  cin >> s;
  for (int i = 0; i <= s.length(); i++) {
    s4 = s.substr(i, 3);
    if (s4 != s3) {
      k = 5;
      s1.push_back(s[i]);
    } else {
      if (k != 0) s1.push_back(' ');
      i = i + 2;
      k = 0;
    }
  }
  cout << s1 << endl;
  return 0;
}
