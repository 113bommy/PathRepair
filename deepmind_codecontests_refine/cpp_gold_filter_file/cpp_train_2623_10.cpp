#include <bits/stdc++.h>
const int N = 100050;
using namespace std;
inline int gi() {
  char ch = getchar();
  int x = 0, q = 0;
  while (ch < '0' || ch > '9') ch == '-' ? q = 1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return q ? (-x) : x;
}
int s[N], t[N], nn[N << 1][2], siz[N], head[N], cnt, S[N], sums, sumt, n;
double ans;
void dfs(int x, int fa) {
  S[x] = s[x], siz[x] = 1;
  for (int i = head[x], y; i; i = nn[i][0])
    if ((y = nn[i][1]) != fa) dfs(y, x), S[x] += S[y], siz[x] += siz[y];
  return;
}
void calc(int x, int fa) {
  for (int i = head[x], y; i; i = nn[i][0])
    if ((y = nn[i][1]) != fa) {
      calc(y, x);
      ans += double(S[y]) / sums * siz[y] * t[x] / sumt;
    }
  ans += double(sums - S[x]) / sums * (n - siz[x]) * t[x] / sumt;
  return;
}
int main() {
  n = gi();
  int u, v;
  for (int i = 2; i <= n; ++i)
    u = gi(), v = gi(), (nn[++cnt][1] = v, nn[cnt][0] = head[u], head[u] = cnt),
    (nn[++cnt][1] = u, nn[cnt][0] = head[v], head[v] = cnt);
  for (int i = 1; i <= n; ++i)
    s[i] = gi(), t[i] = gi(), sums += s[i], sumt += t[i];
  dfs(1, 0), calc(1, 0);
  printf("%.20lf", ans);
  return 0;
}
