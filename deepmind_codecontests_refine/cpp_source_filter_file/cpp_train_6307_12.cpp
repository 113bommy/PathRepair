#include <bits/stdc++.h>
using namespace std;
int cnt[2];
int b[2][7010];
int n;
int status[2][7010], vis[2][7010], out[2][7010];
queue<int> q;
void win(int p, int u) {
  if (status[p][u] == -1) {
    q.push(u << 1 | p);
    status[p][u] = 1;
  }
}
void lose(int p, int u) {
  for (int i = 0; i < cnt[p ^ 1]; i++) {
    win(p ^ 1, (u - b[p ^ 1][i] + n) % n);
  }
}
int main() {
  scanf("%d", &n);
  memset(status, -1, sizeof(status));
  for (int i = 0; i < 2; i++) {
    scanf("%d", &cnt[i]);
    for (int j = 0; j < cnt[i]; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  for (int i = 0; i < n; i++) out[0][i] = cnt[0], out[1][i] = cnt[1];
  status[0][0] = 0;
  status[1][0] = 0;
  out[0][0] = 0;
  out[1][0] = 0;
  lose(1, 0);
  lose(0, 0);
  while (!q.empty()) {
    int u0 = q.front();
    q.pop();
    int u = u0 >> 1, p = u0 & 1;
    vis[p][u] = 1;
    for (int i = 0; i < cnt[p ^ 1]; i++) {
      int ut = (u - b[p ^ 1][i] + n) % n, pt = p ^ 1;
      if (ut == 0) continue;
      out[pt][ut]--;
      if (out[pt][ut] == 0) {
        status[pt][ut] = 0;
        lose(pt, ut);
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < n; j++) {
      if (status[i][j] == 1)
        printf("WIN ");
      else if (status[i][j] == 0)
        printf("LOSE ");
      else
        printf("LOOP ");
    }
    puts("");
  }
  return 0;
}
