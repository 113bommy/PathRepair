#include <bits/stdc++.h>
using namespace std;
int mov[256][2];
int c[111][2];
int a, b, n, i, x;
char s[111];
int f(int a, int b) {
  if (a > 0)
    return b / a;
  else
    return 0;
}
int main() {
  mov['U'][0] = 0;
  mov['U'][1] = 1;
  mov['D'][0] = 0;
  mov['D'][1] = -1;
  mov['L'][0] = -1;
  mov['L'][1] = 0;
  mov['R'][0] = 1;
  mov['R'][1] = 0;
  scanf("%d%d\n", &a, &b);
  gets(s);
  n = strlen(s);
  for (i = 0; i < n; i++) {
    c[i + 1][0] = c[i][0] + mov[s[i]][0];
    c[i + 1][1] = c[i][1] + mov[s[i]][1];
  }
  for (i = 0; i < n; i++) {
    x = max(max(f(c[n][0], a - c[i][0]), f(c[n][1], b - c[i][1])), 0);
    if (x * c[n][0] == a - c[i][0] && c[n][1] * x == b - c[i][1]) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
