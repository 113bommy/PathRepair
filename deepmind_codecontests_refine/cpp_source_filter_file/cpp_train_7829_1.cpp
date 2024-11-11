#include <bits/stdc++.h>
using namespace std;
char s[5][5];
int main() {
  int i, j, m, n, k, t;
  for (i = 0; i < 3; i++) scanf(" %s", s[i]);
  bool bo = true;
  for (i = 0; i < 3; i++)
    for (j = 0; j < i; j++)
      if (s[i][j] != s[2 - i][2 - j]) bo = false;
  if (!bo)
    printf("NO\n");
  else
    printf("YES\n");
}
