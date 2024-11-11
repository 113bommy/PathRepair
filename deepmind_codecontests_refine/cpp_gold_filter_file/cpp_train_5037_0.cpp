#include <bits/stdc++.h>
using namespace std;
const long long mm = 1000000007;
const long long inf = 1e18;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char q[300500], ch[300500], t[300500];
vector<char> s[300500];
vector<int> e[300500];
int len2, n, ans = 0;
int fa[300500], trans[300500][30];
void dfs(int u, int pre) {
  if (u != 1) {
    for (int i = 0; i < (int)s[u].size(); i++) {
      pre = trans[pre][s[u][i] - 'a'];
      if (pre == len2) ans++, pre = fa[pre];
    }
  }
  for (int i = 0; i < (int)e[u].size(); i++) {
    dfs(e[u][i], pre);
  }
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) {
    int x = read();
    scanf("%s", ch);
    for (int j = 0; ch[j]; j++) s[i].push_back(ch[j]);
    e[x].push_back(i);
  }
  scanf("%s", t + 1);
  len2 = strlen(t + 1);
  for (int i = 2, j = 0; i <= len2; i++) {
    while (j && t[j + 1] != t[i]) j = fa[j];
    if (t[j + 1] == t[i]) j++;
    fa[i] = j;
  }
  trans[0][t[1] - 'a'] = 1;
  for (int i = 1; i <= len2 - 1; i++) {
    for (int j = 0; j <= 25; j++)
      if ('a' + j == t[i + 1])
        trans[i][j] = i + 1;
      else
        trans[i][j] = trans[fa[i]][j];
  }
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
