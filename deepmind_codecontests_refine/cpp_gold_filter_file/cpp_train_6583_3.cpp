#include <bits/stdc++.h>
using namespace std;
const int maxN = 8005;
int n;
int G[maxN + 1][maxN + 1];
int deg[maxN + 1];
char s[maxN + 1];
bool vis[maxN + 1];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int cnt = 0;
    for (int j = 1; j <= n / 4; j++) {
      int x = isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
      for (int k = 3; k >= 0; k--) G[i][++cnt] = x >> k & 1;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (G[i][j]) deg[j]++;
  int res = n;
  while (1) {
    int x = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i] && !deg[i]) {
        x = i;
        break;
      }
    if (!x) break;
    vis[x] = true;
    res--;
    ans += (1ll + 614ll * n) * res;
    for (int j = 1; j <= n; j++)
      if (G[x][j]) deg[j]--;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int s = 0, x = 0;
      for (int j = 1; j <= n; j++)
        if (!vis[j] && G[i][j]) {
          s++;
          if (!x || G[x][j]) x = j;
        }
      ans += s;
      for (int j = 1; j <= n; j++)
        if (!vis[j] && i != j && !G[i][j]) ans += G[x][j] ? 2 : 3;
    }
  printf("%lld\n", ans);
  return 0;
}
