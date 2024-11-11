#include <bits/stdc++.h>
using namespace std;
int main() {
  char dir;
  cin >> dir;
  string m;
  cin >> m;
  string kboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
  if (dir == 'R') {
    for (int i = 0; i < m.length(); i++) {
      int index = kboard.find(m[i]);
      cout << kboard[index - 1];
    }
    cout << endl;
  } else {
    for (int i = 0; i < m.length(); i++) {
      int index = kboard.find(m[i]);
      cout << kboard[index + 1];
    }
    cout << endl;
  }
  return 0;
}
