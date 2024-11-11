#include <bits/stdc++.h>
using namespace std;
vector<int> p[4000];
int ans[300000];
int in[4000], out[4000], vis[4000];
char s[300000][4];
int n, cnt;
int js(char ch) {
  if (ch >= 'a' && ch <= 'z')
    return ch - 'a';
  else if (ch >= 'A' && ch <= 'Z')
    return ch - 'A' + 26;
  else if (ch >= '0' && ch <= '9')
    return ch - '0' + 52;
}
char rejs(int d) {
  if (d < 26)
    return 'a' + d;
  else if (d < 52)
    return 'A' + d - 26;
  else
    return '0' + d - 52;
}
void dfs(int u) {
  while (vis[u] < p[u].size()) {
    int v = p[u][vis[u]];
    vis[u]++;
    dfs(v);
    ans[cnt++] = v;
  }
}
int main() {
  int u, v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    u = js(s[i][0]) * 62 + js(s[i][1]) + 1;
    v = js(s[i][1]) * 62 + js(s[i][2]) + 1;
    p[u].push_back(v);
    out[u]++;
    in[v]++;
  }
  int mini = 4000, flag = 0;
  int odd = 0;
  for (int i = 1; i <= 62 * 62; i++) {
    if ((out[i] - in[i] > 1) || (out[i] - in[i] < -1)) {
      flag = 1;
      break;
    }
    if ((out[i] - in[i] == 1) || (out[i] - in[i] == -1)) {
      odd++;
      if (out[i] - in[i] == 1) mini = i;
    }
  }
  if (odd != 0 && odd != 2) flag = 1;
  if (flag)
    printf("NO\n");
  else {
    cnt = 0;
    if (mini == 4000) mini = js(s[0][0]) * 62 + js(s[0][1]) + 1;
    dfs(mini);
    if (cnt == n) {
      printf("YES\n");
      printf("%c%c", rejs((mini - 1) / 62), rejs((mini - 1) % 62));
      for (int i = n - 1; i >= 0; i--) putchar(rejs((ans[i] - 1) % 62));
      puts("");
    } else
      printf("NO\n");
  }
  return 0;
}
