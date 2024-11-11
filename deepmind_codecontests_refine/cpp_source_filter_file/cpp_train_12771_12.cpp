#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
char s[N][N];
int n, m, a, b, c, d;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  n = 50, m = 50;
  for (int i = 1; i <= 25; i++)
    for (int j = 1; j <= 50; j++) {
      if (j <= 25)
        s[i][j] = 'A';
      else
        s[i][j] = 'B';
    }
  for (int i = 26; i <= 50; i++)
    for (int j = 1; j <= 50; j++) {
      if (j <= 25)
        s[i][j] = 'C';
      else
        s[i][j] = 'D';
    }
  a--, b--, c--, d--;
  for (int i = 1; i <= 25 && b; i += 2)
    for (int j = 1; j <= 24 && b; j += 2) s[i][j] = 'B', b--;
  for (int i = 1; i <= 25 && a; i += 2)
    for (int j = 27; j <= n && a; j += 2) s[i][j] = 'A', a--;
  for (int i = 26; i <= n && d; i += 2)
    for (int j = 1; j <= 24 && d; j += 2) s[i][j] = 'D', d--;
  int cnt = 0;
  for (int i = 26; i <= n && c; i += 2)
    for (int j = 27; j <= n && c; j += 2) s[i][j] = 'C', cnt++;
  printf("%d %d\n", n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%c", s[i][j]);
    printf("\n");
  }
  return 0;
}
