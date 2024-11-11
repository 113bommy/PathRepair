#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char a[3][3];
  bool b = true;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> a[i][j];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (a[i][j] != a[2 - i][2 - j]) {
        b = false;
        break;
      }
  if (b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
