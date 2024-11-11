#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
bool letter[27];
char str[MAXN];
char ss[MAXN];
int mp[26][26];
int ans[26][2];
int vis[26];
int dfs(int x, int y) {
  if (x == y) return 1;
  vis[x] = 1;
  for (int i = 0; i < 26; i++) {
    if (vis[i] == 0 && mp[x][i]) {
      if (dfs(i, y)) return 1;
    }
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  scanf("%s", ss);
  int num = 0;
  int binn = 0;
  for (int i = 0; i < n; i++) {
    int c = str[i] - 'a';
    int d = ss[i] - 'a';
    if (letter[c] == 0) {
      num++;
      letter[c] = 1;
    }
    if (letter[d] == 0) {
      num++;
      letter[d] = 1;
    }
    if (c != d) {
      memset(vis, 0, sizeof(vis));
      if (!dfs(c, d)) {
        ans[binn][0] = c;
        ans[binn][1] = d;
        binn++;
        mp[c][d] = 1;
        mp[d][c] = 1;
      }
    }
  }
  if (binn > num - 1) {
    printf("%d\n", n - 1);
    char as;
    int flag = 1;
    for (int i = 0; i < 26; i++) {
      if (flag && letter[i]) {
        flag = 0;
        as = i + 'a';
      } else if (letter[i]) {
        printf("%c %c\n", as, i + 'a');
      }
    }
  } else {
    printf("%d\n", binn);
    for (int i = 0; i < binn; i++) {
      printf("%c %c\n", ans[i][0] + 'a', ans[i][1] + 'a');
    }
  }
  return 0;
}
