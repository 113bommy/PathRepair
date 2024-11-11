#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  string kind[4] = {"rat", "woman", "man", "captain"};
  string s1, s2, test[x][2];
  for (int i = 0; i < x; i++) {
    cin >> s1 >> s2;
    test[i][0] = s1;
    test[i][1] = s2;
  }
  int c = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      if (c != 1) {
        if (test[j][1] == kind[c]) cout << test[j][0] << endl;
      } else {
        if (test[j][1] == kind[1] || test[j][1] == "child")
          cout << test[j][0] << endl;
      }
    }
    c++;
  }
  return 0;
}
