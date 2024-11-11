#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[3];
  bool b = true;
  for (int i = 0; i < 3; i++) cin >> str[i];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (str[i][j] != str[2 - i][2 - j]) {
        b = false;
        return 0;
      }
  b ? cout << "YES" : cout << "NO";
}
