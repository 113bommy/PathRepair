#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000,10240000")
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-10;
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
const int N = 505;
int n, K, f[N][N], sum[N * N], bo[N * N], fa[N * N], ans;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char s[N][N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  n = read();
  K = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.') {
        f[i][j] = (i - 1) * n + j;
        fa[(i - 1) * n + j] = (i - 1) * n + j;
        sum[(i - 1) * n + j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.') {
        for (int l = 0; l < 4; l++) {
          int x = i + dx[l], y = j + dy[l];
          if (f[x][y] == 0 || x < 1 || y < 1 || x > n || y > n) continue;
          int a = find(f[x][y]), b = find(f[i][j]);
          if (a == b) continue;
          sum[a] += sum[b];
          fa[b] = a;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i + K - 1 > n) break;
    for (int j = i; j <= i + K - 1; j++) {
      for (int k = 1; k <= K; k++) {
        sum[find(f[j][k])]--;
      }
    }
    for (int j = 1; j <= n - K + 1; j++) {
      int tmp = 0;
      if (i > 1) {
        for (int k = j; k <= j + K - 1; k++)
          if (bo[find(f[i - 1][k])] == 0 && f[i - 1][k])
            tmp += sum[find(f[i - 1][k])], bo[find(f[i - 1][k])]++;
      }
      if (j > 1) {
        for (int k = i; k <= i + K - 1; k++)
          if (bo[find(f[k][j - 1])] == 0 && f[k][j - 1])
            tmp += sum[find(f[k][j - 1])], bo[find(f[k][j - 1])]++;
      }
      if (i + K - 1 < n) {
        for (int k = j; k <= j + K - 1; k++)
          if (bo[find(f[i + K][k])] == 0 && f[i + K][k])
            tmp += sum[find(f[i + K][k])], bo[find(f[i + K][k])]++;
      }
      if (j + K - 1 < n) {
        for (int k = i; k <= i + K - 1; k++)
          if (bo[find(f[k][j + K])] == 0 && f[k][j + K])
            tmp += sum[find(f[k][j + K])], bo[find(f[k][j + K])]++;
      }
      ans = max(ans, tmp);
      if (i > 1) {
        for (int k = j; k <= j + K - 1; k++) bo[find(f[i - 1][k])] = 0;
      }
      if (j > 1) {
        for (int k = i; k <= i + K - 1; k++) bo[find(f[k][j - 1])] = 0;
      }
      if (i + K - 1 < n) {
        for (int k = j; k <= j + K - 1; k++) bo[find(f[i + K][k])] = 0;
      }
      if (j + K - 1 < n) {
        for (int k = i; k <= i + K - 1; k++) bo[find(f[k][j + K])] = 0;
      }
      if (j != n - K + 1)
        for (int k = i; k <= i + K - 1; k++) {
          sum[find(f[i][j])]++;
          sum[find(f[i][j + K])]--;
        }
    }
    for (int j = i; j <= i + K - 1; j++) {
      for (int k = n; k >= n - K + 1; k--) {
        sum[find(f[j][k])]++;
      }
    }
  }
  cout << ans + K * K;
}
