#include <bits/stdc++.h>
using namespace std;
int p[10004], tot;
bool g[1330], q[1333];
char s[1333], ans[1333];
int vis[44];
void init() {
  int i, j;
  for (i = 2; i * i <= 1003; i++)
    for (j = i * i; j <= 1003; j += i) g[j] = 1;
  g[1] = 1;
  for (i = 2; i <= 1003; i++)
    if (!g[i]) p[tot++] = i;
}
int main() {
  int i, j;
  init();
  int len = strlen(gets(s + 1));
  if (len == 1) {
    puts("YES");
    puts(s + 1);
    return 0;
  }
  for (i = 1; i <= len; i++) vis[s[i] - 'a']++;
  int u = 0;
  while (p[u + 1] < len) u++;
  for (i = 0; i <= u; i++)
    for (j = 1; j <= len / 2; j++)
      if (len / p[i] >= 2) q[j * p[i]] = 1;
  int tt = 0;
  for (i = 1; i <= len; i++)
    if (q[i]) tt++;
  for (i = 0; i < 26; i++)
    if (vis[i] >= tt) break;
  if (i == 26)
    puts("NO");
  else {
    puts("YES");
    int f = i;
    int w = vis[i] - tt;
    int x = 0;
    for (i = 1; i <= len; i++) {
      if (q[i] && vis[f] > 0)
        printf("%c", f + 'a'), vis[f]--;
      else {
        for (j = 0; j < 26; j++)
          if (vis[j] > 0 && j != f) {
            printf("%c", j + 'a');
            vis[j]--;
            break;
          } else if (vis[j] > 0 && j == f && x < w) {
            printf("%c", j + 'a');
            x++;
            vis[j]--;
            break;
          }
      }
    }
    puts("");
  }
  return 0;
}
