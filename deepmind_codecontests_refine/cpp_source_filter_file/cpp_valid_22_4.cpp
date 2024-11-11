#include <bits/stdc++.h>
using namespace std;
const int N = 50;
const int inf = 1 << 30;
long long read() {
  long long a = 0;
  char b = 1, c;
  do
    if ((c = getchar()) == 45) b = -1;
  while (c < 48 || c > 57);
  do a = (a << 3) + (a << 1) + (c & 15);
  while ((c = getchar()) > 47 && c < 58);
  return a * b;
}
void write(long long x, char c) {
  if (x < 0) putchar(45), x = -x;
  char a[20], s = 0;
  do a[++s] = x % 10 | 48;
  while (x /= 10);
  do putchar(a[s]);
  while (--s);
  putchar(c);
}
int a[N], s[N];
long long g[N][N];
set<long long> q;
bool dfs(long long res, int i) {
  if (!i) return q.count(res);
  int t = __builtin_popcountll(res & g[i][s[i]]);
  res &= ~g[i][s[i]];
  for (int j = t + a[i]; j >= t; --j) {
    if (!dfs(res | g[i][j], i - 1)) {
      return 0;
    }
  }
  return 1;
}
bool solve() {
  int n = read(), m = read();
  if (n == 1) return 1;
  long long res = (1LL << n) - 1;
  for (int i = m; i >= 1; --i) {
    s[i] = read();
    for (int j = 1; j <= s[i]; ++j) {
      g[i][j] = 1LL << read();
      if (res & g[i][j]) {
        ++a[i];
        res ^= g[i][j];
      }
      g[i][j] |= g[i][j - 1];
    }
  }
  if (res) return 0;
  for (int i = 0; i <= n; ++i) {
    q.insert(res);
    res |= 1LL << i;
  }
  return dfs(0, m);
}
int main() { puts(solve() ? "ACCEPTED" : "REJECTED"); }
