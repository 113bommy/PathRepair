#include <bits/stdc++.h>
using namespace std;
int n, m;
int st[31][31], sum[31][31], maxv[31][31], minv[31], f[(1 << 21)];
char s[31][31];
inline int read() {
  int sum = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum;
}
int main() {
  n = read();
  m = read();
  int i, j;
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  int c, a;
  for (i = 0; i < n; i++) minv[i] = 1e6 + 10;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      c = s[i][j] - 'a';
      a = read();
      minv[i] = min(minv[i], a);
      st[j][c] |= (1 << i);
      sum[j][c] += a;
      maxv[j][c] = max(maxv[j][c], a);
    }
  int s;
  for (s = 1; s < (1 << n); s++) f[s] = 2e7 + 10;
  for (s = 0; s < (1 << n); s++) {
    for (i = 0; i < n; i++)
      f[s | (1 << i)] = min(f[s | (1 << i)], f[s] + minv[i]);
    for (i = 1; i <= m; i++)
      for (j = 0; j <= 26; j++)
        f[s | st[i][j]] = min(f[s | st[i][j]], f[s] + sum[i][j] - maxv[i][j]);
  }
  cout << f[(1 << n) - 1];
  return 0;
}
