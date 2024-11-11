#include <bits/stdc++.h>
using namespace std;
int N, M, G[2], S[2];
int dist[55][55], mx[55], mn[55], gg[55], ss[55], bb[55];
pair<int, int> gc, bc;
int p, q;
long long cc[55][55][55];
long long dp(int x, int g, int b) {
  if (x == N)
    return G[0] <= g && g <= G[1] && S[0] <= N - g - b && N - g - b <= S[1];
  long long &ret = cc[x][g][b];
  if (ret != -1) return ret;
  ret = 0;
  if (gg[x]) ret += dp(x + 1, g + 1, b);
  if (ss[x]) ret += dp(x + 1, g, b);
  if (bb[x]) ret += dp(x + 1, g, b + 1);
  return ret;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dist[i][j] = i == j ? 0 : 1e9;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    dist[u][v] = w;
    dist[v][u] = w;
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
  for (int i = 0; i < N; i++) {
    mx[i] = -1e9;
    mn[i] = 1e9;
    for (int j = 0; j < N; j++)
      if (i != j) {
        mx[i] = max(mx[i], dist[i][j]);
        mn[i] = min(mn[i], dist[i][j]);
      }
  }
  for (int i = 0; i < 2; i++) {
    scanf("%d", &G[i]);
  }
  for (int i = 0; i < 2; i++) {
    scanf("%d", &S[i]);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (i != j) {
        gc = pair<int, int>(mx[i], i);
        bc = pair<int, int>(mn[j], j);
        if (gc < bc) continue;
        p = i;
        q = j;
        memset(cc, -1, sizeof(cc));
        for (int a = 0; a < N; a++) {
          if (a == p) {
            gg[a] = 1;
            ss[a] = bb[a] = 0;
            continue;
          }
          if (a == q) {
            gg[a] = ss[a] = 0;
            bb[a] = 1;
            continue;
          }
          gg[a] = ss[a] = bb[a] = 0;
          for (int b = 0; b < N; b++)
            if (a != b) {
              if (pair<int, int>(dist[a][b], a) > gc)
                gg[a] = 1;
              else if (pair<int, int>(dist[a][b], a) < bc)
                bb[a] = 1;
              else
                ss[a] = 1;
            }
        }
        ans += dp(0, 0, 0);
      }
  printf("%lld", ans);
}
