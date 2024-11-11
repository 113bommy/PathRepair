#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int vis[30], mark[maxn];
char s[maxn];
bool judge() {
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (vis[i] == 1) {
      cnt++;
    }
  }
  return cnt == 1 ? 1 : 0;
}
int main() {
  int n, flag = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < 26; i++) vis[i] = 2;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    if (s[0] == '?') {
      scanf("%s", s);
      if (flag) {
        ans++;
        continue;
      }
      vis[s[0] - 'a'] = 0;
      if (judge()) flag = 1;
    } else if (s[0] == '.') {
      scanf("%s", s);
      if (flag == 1) {
        continue;
      }
      int len = strlen(s);
      for (int i = 0; i < len; i++) {
        if (vis[s[i] - 'a']) {
          vis[s[i] - 'a'] = 0;
        }
      }
      if (judge()) flag = 1;
    } else {
      scanf("%s", s);
      int len = strlen(s);
      if (flag) {
        ans++;
        continue;
      }
      memset(mark, 0, sizeof(mark));
      for (int i = 0; i < len; i++) {
        mark[s[i] - 'a'] = 1;
        if (vis[s[i] - 'a'] == 2) {
          vis[s[i] - 'a'] = 1;
        }
      }
      for (int i = 0; i < 26; i++) {
        if (vis[i] && !mark[i]) vis[i] = 0;
      }
      if (judge()) flag = 1;
    }
  }
  if (!ans) ans++;
  printf("%d\n", ans - 1);
}
