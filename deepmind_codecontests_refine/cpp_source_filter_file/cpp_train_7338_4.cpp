#include <bits/stdc++.h>
using namespace std;
char s[300003];
int main() {
  int n, m, x, ans = 0;
  char c;
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  s[0] = s[n + 1] = 'x';
  for (int i = 1; i <= n; i++) {
    if (s[i] == '.' && s[i - 1] == '.') ans++;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %c", &x, &c);
    if (c != '.' && s[x] == '.') {
      if (s[x - 1] == '.') ans--;
      if (s[x + 1] == '.') ans--;
    }
    if (c == '.' && s[x] != '.') {
      if (s[x - 1] == '.') ans++;
      if (s[x + 1] == '.') ans++;
    }
    s[x] = c;
    printf("%d", ans);
  }
  return 0;
}
