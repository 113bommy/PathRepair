#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 1e9 + 7;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) re = re * x % p;
  return re;
}
int n, m;
char c[2005][2005];
long long f[2005][2005][2];
int ct1[2005][2005], ct2[2005][2005];
long long s1[2005][2005], s2[2005][2005];
int t1[2005], t2[2005];
long long S1(int x, int l, int r);
long long S2(int y, int l, int r);
long long solve(int x, int y, int id) {
  if (x == n && y == m) return 1;
  if (f[x][y][id] != -1) return f[x][y][id];
  long long ans = 0;
  if (id == 0) {
    int sum = ct2[x + 1][y];
    ans = S2(y, x + 1, x + sum);
  } else {
    int sum = ct1[x][y + 1];
    ans = S1(x, y + 1, y + sum);
  }
  return f[x][y][id] = ans;
}
long long S1(int x, int l, int r) {
  if (t1[x] <= l) return (s1[x][l] - s1[x][r + 1] + p) % p;
  for (int i = t1[x] - 1; i >= l; i--)
    s1[x][i] = (s1[x][i + 1] + solve(x, i, 0)) % p;
  t1[x] = l;
  return (s1[x][l] - s1[x][r + 1] + p) % p;
}
long long S2(int y, int l, int r) {
  if (t2[y] <= l) return (s2[y][l] - s2[y][r + 1] + p) % p;
  for (int i = t2[y] - 1; i >= l; i--)
    s2[y][i] = (s2[y][i + 1] + solve(i, y, 1)) % p;
  t2[y] = l;
  return (s2[y][l] - s2[y][r + 1] + p) % p;
}
int main() {
  read(n, m);
  for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
  if (c[n][m] == 'R') return printf("0\n"), 0;
  if (n == 1 && m == 1) return printf("1\n"), 0;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) ct1[i][j] = ct1[i][j + 1] + (c[i][j] == '.');
  for (int i = 1; i <= m; i++)
    for (int j = n; j >= 1; j--) ct2[j][i] = ct2[j + 1][i] + (c[i][j] == '.');
  memset(f, -1, sizeof(f));
  f[n][m][0] = f[n][m][1] = 1;
  for (int i = 1; i <= n; i++) t1[i] = m + 1;
  for (int i = 1; i <= m; i++) t2[i] = n + 1;
  printf("%lld\n", (solve(1, 1, 0) + solve(1, 1, 1)) % p);
}
