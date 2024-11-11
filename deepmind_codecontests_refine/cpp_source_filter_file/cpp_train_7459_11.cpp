#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int b[2][N];
char p[N], t[N];
int n, m, k;
int dp[2][N];
void pre(bool pos) {
  b[pos][0] = -1;
  for (int i = 1; i <= m; ++i) {
    int j = b[pos][i - 1];
    while (j != -1 and t[j] != t[i - 1]) j = b[pos][j];
    b[pos][i] = j + 1;
  }
}
void kmp(bool pos) {
  int match = 0;
  for (int i = 0; i < n; ++i) {
    while (match != -1 and p[i] != t[match]) match = b[pos][match];
    match += 1;
    dp[pos][i] = match;
    if (match == m) match = b[pos][match];
  }
}
int vis[N];
void add(int pos, int w) {
  while (not vis[w]) {
    vis[w] = pos + 1;
    if (w == 0) break;
    w = b[0][w];
  }
}
int memo[N];
bool vm[N];
int down(int w) {
  if (w <= k) return w;
  if (vm[w]) return memo[w];
  vm[w] = 1;
  return memo[w] = down(b[1][w]);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  scanf("%s", p);
  scanf("%s", t);
  pre(0);
  kmp(0);
  reverse(t, t + m);
  reverse(p, p + n);
  pre(1);
  kmp(1);
  int Max = dp[0][k - 1];
  add(k, Max);
  for (int i = k; i + k - 1 < n; ++i) {
    int need = m - down(dp[1][n - 1 - i]);
    if (vis[need] and need <= k) {
      puts("Yes");
      printf("%d %d\n", vis[need] - k, i + 1);
      return 0;
    }
    add(i + 1, dp[0][i]);
  }
  if (m <= k) {
    for (int i = 0; i + k - 1 < n; ++i) {
      if (dp[0][i] == m) {
        int l = max(i - k + 2, 1);
        if (l + 2 * k - 1 <= n) {
          puts("Yes");
          printf("%d %d\n", l, l + k);
          return 0;
        }
      }
      if (dp[1][n - i - 1] == m) {
        int r = min(n, i + k);
        if (r - 2 * k + 1 >= 1) {
          puts("Yes");
          printf("%d %d\n", r - 2 * k + 1, r - k + 1);
          return 0;
        }
      }
    }
  }
  puts("No");
  return 0;
}
