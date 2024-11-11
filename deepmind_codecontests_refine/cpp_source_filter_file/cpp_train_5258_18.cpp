#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
char str[N], st[N], ans[N];
bool mark[26];
int main() {
  int n, t, f, l, mil, i, j;
  scanf("%d %d", &n, &t);
  scanf("%s %s", str, st);
  mil = f = n - t;
  for (i = 0; i < n; i++)
    if (str[i] == st[i]) mil--, ans[i] = '1';
  if (mil > 0 && mil * 2 > f)
    printf("-1\n");
  else {
    i = 0;
    while (f > 0 && i < n) {
      if (ans[i] == '1') ans[i] = str[i], f--;
      i++;
    }
    f = l = mil;
    for (i = 0; i < n; i++) {
      if (ans[i] >= 'a' && ans[i] <= 'z') continue;
      if (f > 0)
        ans[i] = str[i], f--;
      else if (l > 0)
        ans[i] = st[i], l--;
      else {
        mark[0] = mark[1] = mark[2] = false;
        mark[str[i] - 'a'] = mark[st[i] - 'a'] = true;
        if (!mark[0])
          ans[i] = 'a';
        else if (!mark[1])
          ans[i] = 'b';
        else
          ans[i] = 'c';
      }
    }
    printf("%s\n", ans);
  }
  return 0;
}
