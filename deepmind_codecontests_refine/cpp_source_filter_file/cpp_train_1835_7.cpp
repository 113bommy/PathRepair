#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
char s[maxn];
int vis[30];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    scanf("%s", s);
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      if ((s[i] >= 'A' && s[i] <= 'Z') || (i == n - 1)) {
        ans = max(ans, tmp);
        tmp = 0;
        memset(vis, 0, sizeof(vis));
      } else {
        int id = s[i] - 'a';
        if (vis[id] == 0) {
          tmp++;
          vis[id] = 1;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
