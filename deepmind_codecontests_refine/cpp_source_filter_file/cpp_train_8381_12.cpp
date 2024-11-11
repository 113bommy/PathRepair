#include <bits/stdc++.h>
using namespace std;
int stringtoint(string s) {
  istringstream buffer(s);
  int value;
  buffer >> value;
  return value;
}
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  string t = "";
  for (int i = s.size() - 1; i >= 0; i--) {
    t = "";
    t += s[i];
    int x = stringtoint(t);
    if (x % 4 == 0) {
      cnt += 1;
      t = "";
      if (i - 1 >= 0) {
        t += s[i - 1];
        t += s[i];
        int z = stringtoint(t);
        if (z % 4 == 0) {
          cnt += i;
        }
      }
    } else if (x % 2 == 0 && (i - 1) >= 0) {
      t = "";
      t += s[i - 1];
      t += s[i];
      int y = stringtoint(t);
      if (y % 4 == 0) {
        cnt += (i);
      }
    }
  }
  cout << cnt;
}
