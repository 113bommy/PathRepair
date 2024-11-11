#include <bits/stdc++.h>
using namespace std;
namespace yspm {
inline long long read() {
  long long res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
const long long N = 1010;
char ans[N][N];
long long n, x[N][N], y[N][N];
inline void dfs(long long p, long long q, char now) {
  if (ans[p][q] != '\0') return;
  ans[p][q] = now;
  if (x[p - 1][q] == x[p][q] && y[p - 1][q] == y[p][q]) dfs(p - 1, q, 'D');
  if (x[p + 1][q] == x[p][q] && y[p + 1][q] == y[p][q]) dfs(p + 1, q, 'U');
  if (x[p][q - 1] == x[p][q] && y[p][q - 1] == y[p][q]) dfs(p, q - 1, 'R');
  if (x[p][q + 1] == x[p][q] && y[p][q + 1] == y[p][q]) dfs(p, q + 1, 'L');
  return;
}
inline bool check(long long a, long long b, long long i, long long j, char c1,
                  char c2) {
  if (x[i][j] == -1 && y[i][j] == -1) {
    ans[a][b] = c1;
    if (ans[i][j] == '\0') ans[i][j] = c2;
    return 1;
  } else
    return 0;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j) x[i][j] = read(), y[i][j] = read();
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j)
      if (x[i][j] == i && y[i][j] == j) dfs(i, j, 'X');
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j) {
      if (x[i][j] == -1 && y[i][j] == -1) {
        bool fl = ans[i][j] != '\0';
        if (!fl) fl = check(i, j, i, j + 1, 'R', 'L');
        if (!fl) fl = check(i, j, i, j - 1, 'L', 'R');
        if (!fl) fl = check(i, j, i + 1, j, 'D', 'U');
        if (!fl) fl = check(i, j, i - 1, j, 'U', 'D');
        if (!fl) return puts("INVALID"), 0;
      }
    }
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j)
      if (ans[i][j] == '\0') return puts("INVALID"), 0;
  }
  puts("VALID");
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j) cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
}  // namespace yspm
signed main() { return yspm::main(); }
