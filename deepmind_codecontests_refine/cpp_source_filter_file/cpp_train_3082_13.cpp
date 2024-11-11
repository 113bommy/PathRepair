#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;
char s[50];
bool vis[30];
int solve(int x) {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < a; i++) s[i] = 'a' + i;
  for (int i = a; i < a + b; i++) s[i] = 'a' + x;
  for (int i = b; i < a + b; i++) vis[s[i] - 'a'] = 1;
  int pos = 0;
  for (int i = a + b; i < a * 2 + b; i++) {
    while (vis[pos]) pos++;
    s[i] = 'a' + pos;
    vis[pos] = 1;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = a * 2 + b; i < 2 * (a + b); i++) s[i] = s[a * 2 + b - 1];
  int res = 0;
  if (l <= r) {
    for (int i = l; i <= r; i++)
      if (!vis[s[i] - 'a']) {
        vis[s[i] - 'a'] = 1;
        res++;
      }
  } else {
    for (int i = 0; i < 2 * (a + b); i++) {
      if (i > r && i < l) continue;
      if (!vis[s[i] - 'a']) {
        vis[s[i] - 'a'] = 1;
        res++;
      }
    }
  }
  return res;
}
int main() {
  scanf("%d%d%d%d", &a, &b, &l, &r);
  l--;
  r--;
  if (r - l + 1 >= 2 * (a + b)) {
    int ans = a + max(1, a - b);
    printf("%d\n", ans);
    return 0;
  }
  l %= 2 * (a + b);
  r %= 2 * (a + b);
  int ans = 0x7fffffff;
  for (int i = 0; i < 26; i++) {
    ans = min(ans, solve(i));
  }
  printf("%d\n", ans);
  return 0;
}
