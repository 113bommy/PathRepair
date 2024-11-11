#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int mod = 1e9 + 7;
struct Edge {
  int to, next;
} edge[N * 2];
int head[N], num;
void add_edge(int a, int b) { edge[++num] = (Edge){b, head[a]}, head[a] = num; }
void up(long long &a, long long b) { a = (a + b) % mod; }
int sz[N];
long long f[N][N][N], tf[N][N], s[N], c[N][N];
void dfs(int x, int fa) {
  f[x][0][1] = sz[x] = 1;
  for (int i = head[x]; i; i = edge[i].next)
    if (edge[i].to != fa) {
      dfs(edge[i].to, x);
      for (int j = 0; j <= sz[x] - 1; j++)
        for (int k = 1; k <= sz[x] - j; k++)
          if (f[x][j][k])
            for (int j0 = 0; j0 <= sz[edge[i].to] - 1; j0++)
              for (int k0 = 1; k0 <= sz[edge[i].to] - j0; k0++)
                if (f[edge[i].to][j0][k0]) {
                  up(tf[j + j0][k + k0], f[x][j][k] * f[edge[i].to][j0][k0]);
                  up(tf[j + j0 + 1][k],
                     f[x][j][k] * f[edge[i].to][j0][k0] % mod * k0);
                }
      sz[x] += sz[edge[i].to];
      for (int j = 0; j <= sz[x] - 1; j++)
        for (int k = 1; k <= sz[x] - j; k++)
          f[x][j][k] = tf[j][k], tf[j][k] = 0;
    }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add_edge(a, b);
    add_edge(b, a);
  }
  dfs(1, 0);
  for (int i = 0; i <= n - 1; i++)
    for (int j = 1; j <= n - i; j++) up(s[i + 1], f[1][i][j] * j);
  long long ss = 1;
  s[1] = 1;
  for (int i = 2; i <= n; i++) s[i] = s[i] * ss % mod, ss = ss * n % mod;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i - 1; j++) {
      s[i] = (s[i] - s[j] * c[n - j][n - i] % mod + mod) % mod;
    }
  for (int i = 1; i <= n; i++) printf("%lld ", s[i]);
  return 0;
}
