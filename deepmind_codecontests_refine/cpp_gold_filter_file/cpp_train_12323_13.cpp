#include <bits/stdc++.h>
using namespace std;
int m, n;
char ch[10][10];
int main() {
  int i, j, k, x, y;
  bool ok = 1;
  for (i = 1; i <= 8; i++) scanf("%s", ch[i] + 1);
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= 7; j++) {
      if (ch[i][j] == ch[i][j + 1]) ok = 0;
    }
  }
  if (ok)
    puts("YES");
  else
    puts("NO");
  getchar();
  getchar();
}
