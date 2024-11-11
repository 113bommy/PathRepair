#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
  x = f ? -x : x;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  T y = 1;
  int len = 1;
  for (; y <= x / 10; y *= 10) ++len;
  for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}
const int MAXN = 3, MAXM = 40;
int n, w[MAXN + 5][MAXN + 5];
long long f[MAXM + 5][MAXN + 5][MAXN + 5];
int dfs(int tot, int a, int b, int c) {
  if (~f[tot][a][c]) return f[tot][a][c];
  if (!tot) return f[tot][a][c] = 0;
  return f[tot][a][c] =
             min(dfs(tot - 1, a, c, b) + w[a][c] + dfs(tot - 1, b, a, c),
                 dfs(tot - 1, a, b, c) + w[a][b] + dfs(tot - 1, c, b, a) +
                     w[b][c] + dfs(tot - 1, a, b, c));
}
int main() {
  for (int i = 1; i <= MAXN; ++i)
    for (int j = 1; j <= MAXN; ++j) read(w[i][j]);
  read(n);
  memset(f, -1, sizeof(f));
  write(dfs(n, 1, 2, 3));
  putchar('\n');
  return 0;
}
