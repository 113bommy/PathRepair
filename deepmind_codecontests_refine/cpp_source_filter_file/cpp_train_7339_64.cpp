#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n;
  vector<string> m(8);
  for (int i = 0; i < 8; i++) cin >> m[i];
  ;
  int a = 1e9, b = 1e9;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (m[i][j] == 'W') {
        bool reach = true;
        for (int x = i - 1; x >= 0; x--)
          if (m[x][j] == 'B') reach = false;
        if (reach) a = min(a, i);
      } else if (m[i][j] == 'B') {
        bool reach = true;
        for (int x = i + 1; x < 8; x++)
          if (m[x][j] == 'W') reach = false;
        if (reach) b = min(b, 7 - i);
      }
    }
  }
  if (a < b)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
