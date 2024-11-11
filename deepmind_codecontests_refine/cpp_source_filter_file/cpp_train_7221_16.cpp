#include <bits/stdc++.h>
using namespace std;
int main() {
  bool mx[5][5];
  int r, c, g = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      cin >> mx[i][j];
      if (mx[i][j] == 1) {
        r = i;
        c = j;
      }
    }
  if (r == 0 || r == 4)
    g += 2;
  else if (r == 1 || r == 3)
    g + 1;
  if (c == 0 || c == 4)
    g += 2;
  else if (c == 1 || c == 3)
    g + 1;
  cout << g;
  return 0;
  system("pause");
}
