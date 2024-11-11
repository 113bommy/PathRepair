#include <bits/stdc++.h>
using namespace std;
struct use {
  int to, next;
} e[101005];
int n, m, x, y, z, cnt, sum, num, ans;
int dp[1005], w[1005 * 2], b[1005 * 2], head[1005], f[1005];
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!('0' <= c && c <= '9')) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (('0' <= c && c <= '9')) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int find(int h) {
  if (f[h] == h) return h;
  return f[h] = find(f[h]);
}
int main() {
  n = read(), m = read(), z = read();
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= n; i++) w[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  for (int i = 1; i <= m; i++) f[find(read())] = find(read());
  for (int i = 1; i <= n; i++) {
    e[++cnt] = use{i, head[find(i)]};
    head[find(i)] = cnt;
  }
  num = n;
  for (int i = 1; i <= n; i++) {
    if (head[i]) {
      num++;
      for (int j = head[i]; j; j = e[j].next) {
        w[num] += w[e[j].to];
        b[num] += b[e[j].to];
      }
      e[++cnt] = use{num, head[i]};
      head[i] = cnt;
    }
  }
  for (int i = 1; i <= n; i++)
    if (head[i])
      for (int j = z; j; j--)
        for (int k = head[i]; k; k = e[k].next)
          if (j >= w[e[k].to])
            dp[j] = max(dp[j], dp[j - w[e[k].to]] + b[e[k].to]);
  cout << dp[z];
  return 0;
}
