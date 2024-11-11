#include <bits/stdc++.h>
using namespace std;
int n;
char s[110][110];
bool rep(int i, int j, char c) {
  if (i && s[i - 1][j] == c) return true;
  if (i && j < n - 1 && s[i - 1][j + 1] == c) return true;
  if (j && s[i][j - 1] == c) return true;
  if (i < 4 && j && s[i + 1][j - 1] == c) return true;
  return false;
}
char next(char c) {
  if (c == 'z') return 'a';
  return c + 1;
}
int work() {
  int i, j;
  char c;
  memset(s, 0, sizeof(s));
  c = 'a';
  s[0][0] = s[1][0] = c;
  i = 1;
  while (i < n - 1) {
    while (rep(0, i, c)) c = next(c);
    s[0][i] = s[0][i + 1] = c;
    while (rep(1, i, c)) c = next(c);
    s[1][i] = s[1][i + 1] = c;
    i += 2;
  }
  while (rep(0, i, c)) c = next(c);
  if (n & 1 == 0) s[0][n - 1] = s[1][n - 1] = c;
  for (i = 2; i < 4; i++) {
    for (j = 0; j < n - 1; j += 2) {
      while (rep(i, j, c)) c = next(c);
      s[i][j] = s[i][j + 1] = c;
    }
  }
  if (n % 2 == 0) return 1;
  while (rep(2, n - 1, c)) c = next(c);
  s[2][n - 1] = s[3][n - 1] = c;
}
int main() {
  int i, j;
  cin >> n;
  if (work() == -1)
    printf("-1\n");
  else {
    for (i = 0; i < 4; i++) printf("%s\n", s[i]);
  }
  return 0;
}
