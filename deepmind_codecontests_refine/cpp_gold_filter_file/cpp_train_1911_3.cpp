#include <bits/stdc++.h>
using namespace std;
const int N = 250000 + 5;
const int Log = 20;
template <class T>
inline void getin(T& num) {
  char c;
  bool flag = 0;
  num = 0;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = 1;
  while (c >= '0' && c <= '9') {
    num = num * 10 + c - 48;
    c = getchar();
  }
  if (flag) num = -num;
}
int n, a[N], f[N][25], dp[N][25];
inline pair<int, int> min(pair<int, int> a, pair<int, int> b) {
  return a < b ? a : b;
}
namespace seg {
int M;
pair<int, int> mini[N << 2];
inline void Init() {
  for (M = 1; M < 2 * n; M <<= 1)
    ;
}
inline void update(int x, pair<int, int> val) {
  mini[x += M] = val;
  for (x = x >> 1; x; x >>= 1) mini[x] = min(mini[x << 1], mini[x << 1 | 1]);
}
inline int getmin(int s, int t) {
  if (s == t) return mini[s + M].second;
  pair<int, int> L = mini[s += M], R = mini[t += M];
  while (s ^ t ^ 1) {
    if (~s & 1) L = min(L, mini[s ^ 1]);
    if (t & 1) R = min(R, mini[t ^ 1]);
    s >>= 1, t >>= 1;
  }
  return min(L, R).second;
}
}  // namespace seg
inline void Init() {
  for (int i = 1; i <= Log; i++)
    for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  for (int i = 1; i <= n; i++) dp[i][0] = i - a[i];
  for (int i = 1; i <= Log; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = min(dp[j][i - 1], dp[f[j][i - 1]][i - 1]);
}
inline int walk(int st, int x) {
  int step = 0;
  for (int i = Log; i >= 0; i--)
    if (dp[x][i] > st) step += (1 << i), x = f[x][i];
  return step + 1;
}
inline void insert(int u) {
  f[u][0] = seg::getmin(max(u - a[u], 1), u - 1);
  dp[u][0] = u - a[u];
  seg::update(u, make_pair(u - a[u], u));
  for (int j = 1; j <= Log; j++) {
    f[u][j] = f[f[u][j - 1]][j - 1];
    dp[u][j] = min(dp[u][j - 1], dp[f[u][j - 1]][j - 1]);
  }
}
int main() {
  getin(n);
  seg::Init();
  for (int i = 1; i <= n; i++)
    getin(a[i]), seg::update(i, make_pair(i - a[i], i));
  for (int i = 2; i <= n; i++) f[i][0] = seg::getmin(max(i - a[i], 1), i - 1);
  Init();
  int ans = walk(1, n);
  for (int i = 1; i < n; i++) {
    a[i + n] = a[i];
    insert(i + n);
    ans += walk(i + 1, i + n);
  }
  printf("%d\n", ans);
}
