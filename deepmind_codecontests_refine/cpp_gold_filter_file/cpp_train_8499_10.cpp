#include <bits/stdc++.h>
using namespace std;
const int X = 100;
char s[X][1000], a[15];
int main() {
  int i = 0, j = 0, c = 0, x;
  memset(s, '.', sizeof(s));
  for (x = 0; x < X; x++) s[x][999] = 0;
  scanf("%s", a);
  for (x = 0; a[x]; x++) {
    for (;;) {
      if (c == a[x]) {
        s[++i][0] = 'X', j = 0;
        break;
      } else if (j)
        s[i][j] = 'X', j += 2, c = (c + 255) % 256;
      else
        i += 2, s[i][j] = 'X', j += 2, c = (c + 255) % 256;
    }
  }
  for (x = 0; x < X; x++) puts(s[x]);
}
