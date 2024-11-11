#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[5][5];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) cin >> a[i][j];
  bool ok = true;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] != a[2 - i][2 - j]) ok = false;
    }
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
