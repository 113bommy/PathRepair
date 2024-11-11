#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int dp[40005], p[40004], nt[40004], to[40004], w[40004], num;
void add(int x, int y, int z) {
  num++;
  to[num] = y;
  nt[num] = p[x];
  p[x] = num;
  w[num] = z;
}
void dfs(int x, int f) {
  for (register int i = p[x]; i; i = nt[i]) {
    int k = to[i];
    if (k == f) continue;
    dfs(k, x);
    dp[x] += dp[k] + w[i];
  }
}
void dfs2(int x, int f) {
  for (register int i = p[x]; i; i = nt[i]) {
    int k = to[i];
    if (k == f) continue;
    dp[k] += dp[x] + (w[i] ? -1 : 1);
    dfs2(k, x);
  }
}
int main() {
  int n = read();
  for (register int i = 1; i < n; i++) {
    int a = read(), b = read();
    add(a, b, 0);
    add(b, a, 1);
  }
  dfs(1, 1);
  dfs2(1, 1);
  int ans = 2147483647;
  for (register int i = 1; i <= n; i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  for (register int i = 1; i <= n; i++)
    if (dp[i] == ans) printf("%d ", i);
  return 0;
}
