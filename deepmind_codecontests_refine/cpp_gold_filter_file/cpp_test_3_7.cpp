#include <bits/stdc++.h>
char s[10];
int len, ans;
void dfs(int pos, int cur, int x) {
  if (pos == len) {
    if (cur % 25 == 0) ++ans;
    return;
  }
  if (pos && cur == 0) return;
  if (s[pos] == 'X') {
    if (x != -1)
      dfs(pos + 1, cur * 10 + x, x);
    else {
      for (int i = 0; i < 10; ++i) dfs(pos + 1, cur * 10 + i, i);
    }
  } else if (s[pos] == '_') {
    for (int i = 0; i < 10; ++i) dfs(pos + 1, cur * 10 + i, x);
  } else
    dfs(pos + 1, cur * 10 + (s[pos] ^ 48), x);
}
int main() {
  scanf("%s", s);
  len = strlen(s);
  dfs(0, 0, -1);
  printf("%d\n", ans);
  return 0;
}
