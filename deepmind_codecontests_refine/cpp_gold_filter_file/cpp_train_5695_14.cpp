#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[7];
int vis[6];
int main() {
  int T = 1, cas = 1;
  while (T--) {
    scanf("%s", s);
    for (int i = 0; i < 6; i++) {
      if (s[i] == 'R') vis[0]++;
      if (s[i] == 'O') vis[1]++;
      if (s[i] == 'Y') vis[2]++;
      if (s[i] == 'G') vis[3]++;
      if (s[i] == 'B') vis[4]++;
      if (s[i] == 'V') vis[5]++;
    }
    for (int i = 0; i < 6; i++)
      if (!vis[i]) vis[i] = 9;
    sort(vis, vis + 6);
    if (vis[0] == 1 && vis[1] == 1 && vis[2] == 1 && vis[3] == 1 &&
        vis[4] == 1 && vis[5] == 1)
      puts("30");
    else if (vis[0] == 1 && vis[1] == 1 && vis[2] == 1 && vis[3] == 1 &&
             vis[4] == 2)
      puts("15");
    else if (vis[0] == 1 && vis[1] == 1 && vis[2] == 2 && vis[3] == 2)
      puts("8");
    else if (vis[0] == 2 && vis[1] == 2 && vis[2] == 2)
      puts("6");
    else if (vis[0] == 1 && vis[1] == 1 && vis[2] == 1 && vis[3] == 3)
      puts("5");
    else if (vis[0] == 1 && vis[1] == 2 && vis[2] == 3)
      puts("3");
    else if (vis[0] == 3 && vis[1] == 3)
      puts("2");
    else if (vis[0] == 1 && vis[1] == 1 && vis[2] == 4)
      puts("2");
    else if (vis[0] == 2 && vis[1] == 4)
      puts("2");
    else
      puts("1");
  }
}
