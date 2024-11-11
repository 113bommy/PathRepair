#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  long long sum = ch ^ 48;
  while (isdigit(ch = getchar())) sum = (sum << 1) + (sum << 3) + (ch ^ 48);
  return sum;
}
int n, m, d_in[610], d_ou[610];
int tops, fst[610], to[100010], nxt[100010];
int ntops, top;
long long p, dp[610][310];
queue<int> Q;
long long mat[310][310], ans;
inline long long fst_pow(long long x, long long p, long long mod) {
  long long re = 1;
  while (p) {
    if (p & 1) re = re * x % mod;
    x = x * x % mod, p >>= 1;
  }
  return re;
}
inline void add_edge(int u, int v) {
  to[tops] = v, nxt[tops] = fst[u], fst[u] = tops++;
}
inline void det() {
  ans = 1;
  int tmp, t;
  for (int i = 0; i < ntops; i++) {
    if (mat[i][i] == 0) {
      for (int j = i + 1; j < ntops; j++)
        if (mat[j][i] != 0) {
          for (int k = i; k < ntops; k++)
            mat[i][k] = (mat[i][k] + mat[j][k]) % p;
          break;
        }
      if (mat[i][i] == 0) {
        ans = 0;
        return;
      }
    }
    ans = 1ll * ans * mat[i][i] % p;
    tmp = (p - fst_pow(mat[i][i], p - 2, p)) % p;
    for (int j = i + 1; j < ntops; j++)
      if (mat[j][i] != 0) {
        t = 1ll * tmp * mat[j][i] % p;
        for (int k = i; k < ntops; k++)
          mat[j][k] = (mat[j][k] + 1ll * mat[i][k] * t % p) % p;
      }
  }
}
int main() {
  int u, v;
  n = read(), m = read(), p = read();
  memset(fst, -1, sizeof(fst));
  for (int i = 0; i < m; i++) {
    u = read(), v = read();
    d_in[v]++, d_ou[u]++;
    add_edge(u, v);
  }
  for (int i = 1; i <= n; i++)
    if (d_in[i] == 0) {
      Q.push(i);
      dp[i][++ntops] = 1;
    }
  int now;
  while (!Q.empty()) {
    now = Q.front(), Q.pop();
    for (int i = fst[now]; i != -1; i = nxt[i]) {
      if (--d_in[to[i]] == 0) Q.push(to[i]);
      for (int j = 1; j <= ntops; j++)
        dp[to[i]][j] = (dp[to[i]][j] + dp[now][j]) % p;
    }
  }
  for (int i = 1; i <= n; i++)
    if (d_ou[i] == 0) {
      top++;
      for (int j = 1; j <= ntops; j++) {
        mat[top - 1][j - 1] = dp[i][j];
      }
    }
  det();
  printf("%lld\n", ans);
  return 0;
}
