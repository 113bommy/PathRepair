#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
const int N = 1e6 + 5;
int n;
int a[2][N], p[3][N];
map<long long, int> mp[3];
map<int, int> f[N];
int dfs(int i, int j) {
  if (i == 0 && j == 0) return 0;
  if (f[i].count(j)) return f[i][j];
  f[i][j] = 0;
  if (p[0][i] != -1 && p[0][i] > p[1][j])
    f[i][j] = max(f[i][j], dfs(p[0][i], j) + 1);
  if (p[1][j] != -1 && p[1][j] >= p[0][i])
    f[i][j] = max(f[i][j], dfs(i, p[1][j]) + 1);
  if (p[2][min(i, j)] != -1)
    f[i][j] = max(f[i][j], dfs(p[2][min(i, j)], p[2][min(i, j)]) + 1);
  return f[i][j];
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[0][i] = read();
  for (int i = 1; i <= n; i++) a[1][i] = read();
  mp[0][0] = 0, mp[1][0] = 0, mp[2][0] = 0;
  long long s[3] = {0, 0, 0};
  memset(p, -1, sizeof(p));
  for (int i = 1; i <= n; i++) {
    s[0] += a[0][i], s[1] += a[1][i], s[2] += a[0][i] + a[1][i];
    if (mp[0].count(s[0])) p[0][i] = mp[0][s[0]];
    if (mp[1].count(s[1])) p[1][i] = mp[1][s[1]];
    if (mp[2].count(s[2])) p[2][i] = mp[2][s[2]];
    mp[0][s[0]] = i, mp[1][s[1]] = i, mp[2][s[2]] = i;
    p[0][i] = max(p[0][i], p[0][i - 1]);
    p[1][i] = max(p[1][i], p[1][i - 1]);
    p[2][i] = max(p[2][i], p[2][i - 1]);
  }
  printf("%d", dfs(n, n));
  return 0;
}
