#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[10][10];
  int i, j, a, b, c = 0;
  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++) cin >> ch[i][j];
  cin >> a >> b;
  a %= 3;
  b %= 3;
  if (!a)
    a = 6;
  else if (a == 1)
    a = 0;
  else
    a = 3;
  if (!b)
    b = 6;
  else if (b == 1)
    b = 0;
  else
    b = 3;
  for (i = a; i < a + 3; i++)
    for (j = b; j < b + 3; j++)
      if (ch[i][j] == '.') {
        c = 1;
        ch[i][j] = '!';
      }
  if (!c)
    for (i = 0; i < 9; i++)
      for (j = 0; j < 9; j++)
        if (ch[i][j] == '.') {
          ch[i][j] = '!';
        }
  for (i = 0; i < 9; i++) {
    if (!((i) % 3)) cout << "\n";
    for (j = 0; j < 9; j++) {
      if (!((j) % 3) && j) cout << " ";
      cout << ch[i][j];
    }
    cout << "\n";
  }
  return 0;
}
