#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char ch;
  int x = -1, y, z;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch == 'B') {
        if (x == -1)
          x = i, z = j, y = i;
        else
          y = i;
      }
    }
  int r = ((x + y) / 2) + 1, c = (((y - x)) / 2) + z + 1;
  cout << r << " " << c;
  return 0;
}
