#include <bits/stdc++.h>
using namespace std;
int n, m, k, xx;
int star[50005], dif[50005];
int pos[50005], tail;
int len[50005];
int dist[50005];
int cost[21][21];
int f[1 << 21];
queue<int> q;
void bfs(int s) {
  memset(dist, 0x3f, sizeof(dist));
  q.push(pos[s]);
  dist[pos[s]] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= k; i++) {
      int a = x - len[i];
      int b = x + len[i];
      if (a >= 1 && dist[a] == 0x3f3f3f3f) {
        dist[a] = dist[x] + 1;
        q.push(a);
      }
      if (b <= n + 1 && dist[b] == 0x3f3f3f3f) {
        dist[b] = dist[x] + 1;
        q.push(b);
      }
    }
  }
  for (int i = 1; i <= tail; i++) {
    if (dist[pos[i]] != 0x3f3f3f3f) {
      cost[s][i] = dist[pos[i]];
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) cin >> xx, star[xx] = 1;
  for (int i = 1; i <= k; i++) cin >> len[i];
  for (int i = 1; i <= n; i++) {
    if (!star[i]) continue;
    dif[i] ^= 1, dif[i + 1] ^= 1;
  }
  for (int i = 1; i <= n + 1; i++) {
    if (dif[i]) pos[++tail] = i;
  }
  memset(cost, 0x3f, sizeof(cost));
  for (int i = 1; i <= tail; i++) bfs(i);
  int all = (1 << tail) - 1;
  memset(f, 0x3f, sizeof(f));
  f[all] = 0;
  for (int i = all; i >= 0; i--) {
    for (int j = 1; j <= tail; j++) {
      if (!((1 << (j - 1)) & i)) continue;
      for (int k = j + 1; k <= tail; k++) {
        if (!((1 << (k - 1)) & i)) continue;
        int x = ~((~i) | (1 << (j - 1)) | (1 << (k - 1)));
        f[x] = min(f[x], f[i] + cost[j][k]);
      }
    }
  }
  if (f[0] == 0x3f3f3f3f)
    puts("-1");
  else
    cout << f[0] << endl;
  return 0;
}
