#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string a = "hello";
  int x = 0, y = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == a[x]) {
      x++;
      y++;
    }
  }
  if (y == 5) {
    cout << "YES";
  } else {
    cout << "No";
  }
}
