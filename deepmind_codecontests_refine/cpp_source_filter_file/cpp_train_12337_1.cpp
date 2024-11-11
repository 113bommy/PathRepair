#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[200005];
int num[28];
char x[1], y[1];
int main() {
  int j, i;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (i = 0; i < 28; ++i) num[i] = i;
  for (i = 1; i <= m; ++i) {
    scanf("%1s%1s", x, y);
    if (x[0] == y[0]) continue;
    for (j = 0; j < 26; ++j)
      if (num[j] == x[0] - 'a')
        num[j] = y[0] - 'a';
      else if (num[j] == y[0] - 'a')
        num[j] = x[0] - 'a';
  }
  for (i = 0; i < n; ++i) s[i] = num[s[i] - 'a'] + 'a';
  printf("%s\n", s);
  return 0;
}
