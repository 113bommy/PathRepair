#include <bits/stdc++.h>
using namespace std;
const int maxn = 100009;
int Dist[maxn][9], D[9][9], f[9][1 << 8];
int a[maxn], n, best, ans, dist;
char s[maxn];
long long tot;
int q[maxn], l, r, u;
inline void update(int v, int c, int dis) {
  if (Dist[v][c] <= dis) return;
  Dist[v][c] = dis;
  q[r++] = v;
}
void bfs(int c) {
  l = r = 0;
  q[r++] = n + c;
  Dist[n + c][c] = -1;
  while (l < r) {
    u = q[l++];
    if (u >= n) {
      for (int i = (0); i <= (n - 1); i++)
        if (a[i] == u - n) update(i, c, Dist[u][c] + 1);
      continue;
    }
    if (u >= 1) {
      update(u - 1, c, Dist[u][c] + 1);
      update(n + a[u - 1], c, Dist[u][c] + 1);
    }
    if (u <= n - 2) {
      update(u + 1, c, Dist[u][c] + 1);
      update(n + a[u + 1], c, Dist[u][c] + 1);
    }
    D[a[u]][c] = min(D[a[u]][c], Dist[u][c]);
  }
}
void updans(int now, int cnt) {
  if (now < ans) return;
  if (now == ans)
    tot += cnt;
  else {
    ans = now;
    tot = cnt;
  }
}
void add(int x) {
  int mask = 0;
  for (int i = (0); i <= (7); i++) mask |= (Dist[x][i] - D[a[x]][i]) << i;
  f[a[x]][mask]++;
}
int main() {
  scanf("%d%s", &n, &s);
  for (int i = (0); i <= (n - 1); i++) a[i] = s[i] - 'a';
  memset(Dist, 0x3f, sizeof Dist);
  memset(D, 0x3f, sizeof D);
  for (int i = (0); i <= (7); i++) bfs(i);
  for (int i = (0); i <= (n - 1); i++) {
    for (int j = (max(0, i - 15)); j <= (i - 1); j++) {
      best = i - j;
      for (int c = (0); c <= (7); c++)
        best = min(best, Dist[i][c] + Dist[j][c] + 1);
      updans(best, 1);
    }
    if (i >= 16) add(i - 16);
    for (int c = (0); c <= (7); c++)
      for (int mask = (0); mask <= (255); mask++)
        if (f[c][mask] > 0) {
          dist = 15;
          for (int k = (0); k <= (7); k++)
            dist = min(dist, Dist[i][k] + D[c][k] + (mask >> k & 1) + 1);
          updans(dist, f[c][mask]);
        }
  }
  printf("%d %I64d\n", ans, tot);
  return 0;
}
