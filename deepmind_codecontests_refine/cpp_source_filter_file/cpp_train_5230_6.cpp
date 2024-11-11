#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 100010;
const int INF = 2147483600;
int top;
int sta[19];
bool vis[19];
long long h2[1 << 19], h[1 << 19];
int tmp[19][(1 << 19)];
long long sum = 0;
long long f[(1 << 19)][19], cnt[1 << 19], g[19][(1 << 19)];
int d[21][21];
char str[MAXN + 1];
int all = 0;
inline void dfs2(int k, int now) {
  if (k == top + 1) {
    h2[now] += sum;
    return;
  }
  now <<= 1;
  bool flag = false;
  for (int i = 1; i <= top; i++) {
    if (sta[i] != sta[i - 1]) flag = 0;
    if (i > 1 && sta[i] == sta[i - 1] && flag) continue;
    if (vis[i]) continue;
    flag = 1;
    vis[i] = 1;
    dfs2(k + 1, (now << (sta[i] - 1)) | ((1 << (sta[i] - 1)) - 1));
    vis[i] = 0;
  }
  return;
}
int N;
inline void dfs(int K, int Last) {
  if (K == N) {
    for (int i = 1; i <= N; i++)
      for (int j = (1 << N) - 1; j >= 0; j--)
        if (j & (1 << (i - 1))) h[j] -= h[j ^ (1 << (i - 1))];
    sum = h[(1 << N) - 1];
    for (int i = 1; i <= top; i++) vis[i] = 0;
    dfs2(1, 0);
    return;
  }
  for (int j = 0; j < (1 << N); j++) tmp[top][j] = h[j];
  for (int i = Last; i <= N - K; i++) {
    for (int j = 0; j < (1 << N); j++) h[j] = tmp[top][j] * g[i][j];
    sta[++top] = i;
    dfs(K + i, i);
    --top;
  }
}
int main() {
  N = read();
  for (int i = 1; i <= N; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= N; j++) d[i][j] = str[j] - '0';
  }
  for (int i = 1; i <= N; i++) f[(1 << (i - 1))][i] = 1;
  for (int i = 1; i < (1 << N); i++) {
    cnt[i] = cnt[i - (i & (-i))] + 1;
    for (int j = 1; j <= N; j++) {
      if (!((i >> (j - 1)) & 1)) continue;
      for (int k = 1; k <= N; k++) {
        if (!((i >> (k - 1)) & 1) && d[j][k])
          f[i | (1 << (k - 1))][k] += f[i][j];
      }
    }
  }
  for (int i = 1; i < (1 << N); i++)
    for (int j = 1; j <= N; j++) g[cnt[i]][i] += f[i][j];
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < (1 << N); j++)
        if (!(j & (1 << (i - 1)))) g[k][j ^ (1 << (i - 1))] += g[k][j];
    }
  for (int j = 0; j < (1 << N); j++) h[j] = 1;
  dfs(0, 1);
  for (int i = 1; i <= N; i++) {
    for (int j = (1 << (N - 1)) - 1; j >= 0; j--)
      if (!(j & (1 << (i - 1)))) h2[j] -= h2[j | (1 << (i - 1))];
  }
  for (int i = 0; i < (1 << (N - 1)); i++) printf("%lld ", h2[i]);
  return 0;
}
