#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int c[4] = {8, 6, 9, 1};
int ch[10], d[10];
char gh, ans[maxn];
bool vis[4];
void dfs(int x, int w) {
  if (x >= 4) {
    d[w % 7] = w;
    return;
  } else {
    for (int i = 0; i <= 3; i++) {
      if (!vis[i]) {
        vis[i] = true;
        dfs(x + 1, w * 10 + c[i]);
        vis[i] = false;
      }
    }
  }
}
int main() {
  dfs(0, 0);
  while (scanf("%c", &gh) != EOF) {
    if (gh >= '0' && gh <= '9') ch[gh - '0']++;
  }
  ch[8]--;
  ch[6]--;
  ch[9]--;
  ch[1]--;
  int len = 0, tot = 0, w = 0;
  for (int i = 9; i >= 1; i--) {
    for (int j = 1; j <= ch[i]; j++) {
      len++;
      ans[len] = i;
      w = (w * 10 + i) % 7;
    }
  }
  if (len == 0) {
    printf("%d", d[0]);
    for (int i = 1; i <= ch[0]; i++) printf("0");
    printf("\n");
  } else {
    for (int i = 1; i <= ch[0]; i++) {
      len++;
      ans[len] = 0;
      w = w * 10 % 7;
    }
    w = w * 10000 % 7;
    for (int i = 1; i <= len; i++) printf("%d", ans[i]);
    printf("%d\n", d[7 - w]);
  }
  return 0;
}
