#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - 48;
  return n;
}
const int maxn = 2e5 + 5;
int t, n, i, j, a[maxn], b[maxn], S, T, f[maxn], d[maxn];
int x, y, lc, len, B;
bool bz[maxn], bk[maxn];
vector<int> g[maxn], c;
long long ans;
void dfs(int x, int fa) {
  f[x] = fa, d[x] = fa != -1 ? d[fa] + 1 : 0;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (y != fa) dfs(y, x);
  }
}
int main() {
  n = read();
  for (i = 0; i <= n - 1; i++) a[i] = read(), S = a[i] ? S : i;
  for (i = 0; i <= n - 1; i++) b[i] = read(), T = b[i] ? T : i;
  for (i = 1; i <= n - 1; i++) {
    int x = read() - 1, y = read() - 1;
    g[x].push_back(y), g[y].push_back(x);
  }
  dfs(T, -1), ans = d[S];
  for (i = S; i != T; i = f[i]) bk[i] = 1, swap(a[i], a[f[i]]);
  x = y = -1, bk[T] = 1;
  for (i = 0; i <= n - 1; i++)
    if (a[i] != b[i]) x = x == -1 || d[i] > d[x] ? i : x;
  if (x < 0) return printf("0 %d\n", ans), 0;
  for (i = x; a[i] != b[i]; i = f[i]) c.push_back(i), bz[i] = 1;
  for (i = 0; i <= n - 1; i++)
    if (!bz[i] && a[i] != b[i]) y = y == -1 || d[i] > d[y] ? i : y;
  if (y < 0)
    y = f[c.back()];
  else {
    reverse(c.begin(), c.end());
    for (i = y; a[i] != b[i]; i = f[i]) c.push_back(i), bz[i] = 1;
    for (i = 0; i <= n - 1; i++)
      if (!bz[i] && a[i] != b[i]) return puts("-1"), 0;
  }
  for (i = x, j = y; i != j;)
    if (d[i] > d[j])
      i = f[i];
    else
      j = f[j];
  lc = i, len = c.size();
  if (a[lc] != b[lc] || (d[x] + d[y] - d[lc] * 2 != len)) return puts("-1"), 0;
  for (i = 0; i <= len - 1; i++)
    if (a[c[i]] == b[c[0]]) break;
  B = i;
  for (i = 0; i <= len - 1; i++)
    if (a[c[(i + B) % len]] != b[c[i]]) return puts("-1"), 0;
  if (bk[c[0]] || bk[c[len - 1]]) {
    if (bk[c[len - 1]]) reverse(c.begin(), c.end()), B = len - B;
    for (i = 0; i <= len - 1; i++)
      if (!bk[c[i]]) break;
    long long s1 = (long long)B * (len + 1) - i * 2,
              s2 = (long long)(len - B) * (len + 1);
    ans += (s1 < s2 ? s1 : s2);
  } else
    ans += (long long)(B < len - B ? B : len - B) * (len + 1);
  for (; !bk[lc]; lc = f[lc]) ans += 2;
  if (x > y) swap(x, y);
  printf("%d %d %lld\n", x + 1, y + 1, ans);
}
