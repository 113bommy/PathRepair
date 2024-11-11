#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
char *s[maxn], *p, buf[maxn * 2];
char t[maxn];
int alp[30][30], d[30], is[30], vis[30];
int ct;
bool dfs(int u) {
  t[ct++] = u + 'a';
  vis[u] = 1;
  int cnt = 0, p = -1;
  for (int i = 0; i < 26; i++) {
    if (alp[u][i]) cnt++, p = i;
  }
  if (cnt > 1) return false;
  if (cnt == 0) {
    t[ct] = 0;
    return true;
  }
  if (vis[p]) return 0;
  return dfs(p);
}
int main(void) {
  int n;
  scanf("%d", &n);
  p = buf;
  for (int i = 1; i <= n; i++) {
    scanf("%s", p);
    s[i] = p;
    p += strlen(p) + 1;
  }
  for (int i = 1; i <= n; i++) {
    is[s[i][0] - 'a'] = 1;
    for (int j = 1; s[i][j]; j++) {
      alp[s[i][j - 1] - 'a'][s[i][j] - 'a'] = 1;
      d[s[i][j] - 'a']++;
      is[s[i][0] - 'a'] = 1;
    }
  }
  int flag = 0, yes = 0;
  for (int i = 0; i < 26; i++)
    if (is[i] == 1) {
      if (d[i] == 0) {
        yes = 1;
        if (dfs(i) == false) {
          flag = 1;
          break;
        }
      }
    }
  for (int i = 0; i < 26; i++)
    if (is[i] && vis[i] == 0) {
      flag = 1;
    }
  if (flag || yes == 0) {
    printf("NO\n");
    return 0;
  }
  printf("%s\n", t);
  return 0;
}
