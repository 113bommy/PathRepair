#include <bits/stdc++.h>
using namespace std;
int i, j, v[200010], a, b;
char s[200010];
int main() {
  i = 'q';
  v[i] = 9;
  i = 'r';
  v[i] = 5;
  i = 'b';
  v[i] = 3;
  i = 'k';
  v[i] = 3;
  i = 'p';
  v[i] = 1;
  i = 'Q';
  v[i] = 9;
  i = 'R';
  v[i] = 5;
  i = 'B';
  v[i] = 3;
  i = 'K';
  v[i] = 3;
  i = 'P';
  v[i] = 1;
  for (i = 1; i <= 8; i++) {
    scanf("%s", s);
    for (j = 0; j < 8; j++)
      if (s[j] != '.') {
        if (s[j] >= 97)
          a = a + v[s[j]];
        else
          b = b + v[s[j]];
      }
  }
  if (a < b)
    printf("White");
  else if (a == b)
    printf("Draw");
  else
    printf("Black");
}
