#include <bits/stdc++.h>
using namespace std;
int n, k, len;
char s[100005];
int ch[100005][26], cnt = 1, dp[100005][2], rt = 1;
void Insert(int now, int loc) {
  if (loc >= len) return;
  if (!ch[now][s[loc] - 'a']) ch[now][s[loc] - 'a'] = ++cnt;
  Insert(ch[now][s[loc] - 'a'], loc + 1);
}
void dfs(int now) {
  bool flag = 0;
  dp[now][0] = 0, dp[now][1] = 1;
  for (int i = 0; i < 26; i++)
    if (ch[now][i]) {
      flag = 1;
      dfs(ch[now][i]);
      if (dp[ch[now][i]][0] == 0) dp[now][0] = 1;
      if (dp[ch[now][i]][1] == 1) dp[now][1] = 0;
    }
  if (!flag) dp[now][0] = 0, dp[now][0] = 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%s", s), len = strlen(s), Insert(rt, 0);
  dfs(rt);
  if ((dp[rt][0] && dp[rt][1] == 0) || (dp[rt][0] && (k % 2 == 1)))
    puts("First");
  else
    puts("Second");
}
