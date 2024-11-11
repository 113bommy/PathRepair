#include <bits/stdc++.h>
using namespace std;
int main(void) {
  char t[4][4];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cin >> t[i][j];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      int w = 0, b = 0;
      for (int l = 0; l < 2; l++)
        for (int k = 0; k < 2; k++)
          if (t[i + l][j + k] == '#')
            w++;
          else
            b++;
      if (w == 3 || b == 3) {
        cout << "YES" << endl;
        return 0;
      }
    }
  cout << "NO" << endl;
}
