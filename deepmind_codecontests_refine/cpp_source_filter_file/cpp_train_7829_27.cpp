#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; i < 3; i++) cin >> a[i][j];
  for (int i = 0; i < 3; i++)
    for (int j = 0; i < 3; i++)
      if (a[i][j] != a[2 - i][2 - j]) {
        cout << "NO";
        return (0);
      }
  cout << "YES";
}
