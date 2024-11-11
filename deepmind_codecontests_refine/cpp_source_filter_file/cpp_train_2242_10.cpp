#include <bits/stdc++.h>
using namespace std;
int n;
char to[100005];
int step[100005];
bool vis[100005];
int loc;
int main() {
  while (~scanf("%d", &n)) {
    getchar();
    scanf("%s", &to);
    for (int i = 1; i <= n; i++) scanf("%d", &step[i]);
    loc = 1;
    memset(vis, 0, sizeof(vis));
    bool flag = 0;
    while (loc >= 1 && loc <= n) {
      if (vis[loc]) {
        flag = 1;
        break;
      }
      vis[loc] = 1;
      if (to[loc] == '>')
        loc += step[loc];
      else
        loc -= step[loc];
    }
    if (flag)
      printf("INFINITE\n");
    else
      printf("FINITE\n");
  }
  return 0;
}
