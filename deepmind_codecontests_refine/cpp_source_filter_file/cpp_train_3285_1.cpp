#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)998244353;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
const int N = 600;
int n;
long long C[N][N];
long long S[N][N];
int c1, c2, c3, fullCycle;
int g[N], revG[N];
bool used[N];
long long ans[N];
long long cur[N];
long long cur2[N];
long long f[N];
void precalc() {
  for (int i = 0; i < N; i++) C[i][0] = C[i][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j < i; j++) C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
  S[0][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      S[i][j] = add(S[i - 1][j - 1], mult(i - 1, S[i - 1][j]));
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = mult(f[i - 1], i);
  return;
}
void read() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) g[i] = revG[i] = -1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 0) continue;
    x--;
    x += n;
    g[i] = x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 0) continue;
    x--;
    g[n + i] = x;
  }
  for (int i = 0; i < 2 * n; i++) {
    if (g[i] != -1) revG[g[i]] = i;
  }
  for (int v = 0; v < 2 * n; v++) {
    if (used[v]) continue;
    if (revG[v] != -1) continue;
    int u = v;
    while (g[u] != -1) {
      used[u] = 1;
      u = g[u];
    }
    used[u] = 1;
    if (v < n && u < n)
      c3++;
    else if (v < n && u >= n)
      c1++;
    else if (v >= n && u < n)
      c2++;
  }
  for (int v = 0; v < 2 * n; v++) {
    if (used[v]) continue;
    int u = v;
    while (!used[u]) {
      used[u] = 1;
      u = g[u];
    }
    fullCycle++;
  }
  return;
}
int main() {
  precalc();
  read();
  for (int x = 0; x <= c1; x++)
    for (int y = 0; y <= c2; y++) {
      memset(cur, 0, sizeof cur);
      memset(cur2, 0, sizeof cur2);
      for (int i = 0; i <= c1 - x; i++)
        for (int j = 0; j <= c2 - y; j++)
          cur[i + j] += mult(S[c1 - x][i], S[c2 - y][j]);
      for (int i = 0; i <= c1 + c2 - x - y; i++) cur[i] %= MOD;
      for (int i = 0; i <= c1 + c2 - x - y; i++)
        for (int j = 0; j <= c3; j++) cur2[i + j] += mult(cur[i], S[c3][j]);
      int p = c1 + c2 + c3 - x - y;
      for (int i = 0; i <= p; i++) cur2[i] %= MOD;
      long long Q = mult(mult(C[c1][x], f[x]), mult(C[c2][y], f[y]));
      if (c3 > 0)
        Q = mult(Q, mult(C[c3 + x - 1][x], C[c3 + y - 1][y]));
      else {
        if (x > 0 || y > 0) Q = 0;
      }
      for (int i = 0; i <= p; i++) ans[i] = add(ans[i], mult(Q, cur2[i]));
    }
  for (int i = n; i >= fullCycle; i--) ans[i] = ans[i - fullCycle];
  for (int i = 0; i < fullCycle; i++) ans[i] = 0;
  for (int i = 0; i < n; i++) printf("%lld ", mult(f[c3], ans[n - i]));
  printf("\n");
  return 0;
}
