#include <bits/stdc++.h>
using namespace std;
struct wk {
  int num, cnt;
};
int dis[20][20][20][20], base[2000100];
char In[2000100];
queue<wk> q;
int main() {
  int i, j, k, o;
  for (i = 0; i < 10; ++i)
    for (j = 0; j < 10; ++j)
      for (k = 0; k < 10; ++k)
        for (o = 0; o < 10; ++o) {
          bool mark[200];
          dis[i][j][k][o] = -1;
          memset(mark, 0, sizeof(mark));
          q.push((wk){k, 0});
          while (!q.empty()) {
            wk now = q.front();
            q.pop();
            if (now.num == o && now.cnt) {
              dis[i][j][k][o] = now.cnt;
              break;
            }
            if (mark[now.num]) continue;
            mark[now.num] = 1;
            q.push((wk){(now.num + i) % 10, now.cnt + 1});
            q.push((wk){(now.num + j) % 10, now.cnt + 1});
          }
          while (!q.empty()) q.pop();
        }
  cin >> (In + 1);
  int ans = 0, N = strlen(In + 1);
  for (i = 1; i <= N; ++i) base[i] = In[i] - '0';
  for (i = 0; i < 10; ++i, puts(""))
    for (j = 0; j < 10; ++j) {
      for (ans = 0, k = 2; k <= N; ++k) {
        if (dis[i][j][base[k - 1]][base[k]] == -1) {
          printf("-1 "), ans = 0;
          break;
        }
        ans += dis[i][j][base[k - 1]][base[k]];
      }
      if (ans) printf("%d ", ans - N + 1);
    }
}
