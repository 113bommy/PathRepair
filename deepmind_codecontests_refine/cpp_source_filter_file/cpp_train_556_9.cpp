#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  int x = 0;
  int go[5][5];
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) cin >> go[i][j], x += go[i][j];
  int a, b, c;
  int bb, cc;
  bb = go[0][1] + go[0][2] - go[1][0] - go[1][2];
  cc = go[0][1] + go[0][2] - go[2][0] - go[2][1];
  bool ok = true;
  int n = 100000;
  for (i = 1; i <= 10; i++) {
    a = i;
    b = bb + a;
    c = cc + a;
    if (a < 1 || a > n || b < 1 || b > n || c < 1 || c > n) continue;
    if (a + go[0][1] + go[0][2] == b + go[1][0] + go[1][2] &&
        a + go[0][1] + go[0][2] == c + go[2][1] + go[2][0])
      if (a + go[1][0] + go[2][0] == b + go[0][1] + go[2][1] &&
          a + go[1][0] + go[2][0] == c + go[0][2] + go[1][2])
        if (a + b + c == go[0][2] + b + go[2][0]) break;
  }
  go[0][0] = a;
  go[1][1] = b;
  go[2][2] = c;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) cout << go[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
