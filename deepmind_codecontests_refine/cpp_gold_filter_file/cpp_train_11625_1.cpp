#include <bits/stdc++.h>
using namespace std;
char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
void Read(int& x) {
  char c = nc();
  for (; c < '0' || c > '9'; c = nc())
    ;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - 48, c = nc())
    ;
}
const int N = 300010;
const int M = 19;
int n, m, x, y;
int t[N << 1], nx[N << 1], h[N], num;
int f[N], c[N], dp[N][M];
int a[N], l, cur[N];
vector<pair<int, int> > g[N];
long long Res, Ans;
void Add(int x, int y) {
  t[++num] = y;
  nx[num] = h[x];
  h[x] = num;
}
bool Cmp(int x, int y) { return x > y; }
void Dfs(int x, int y) {
  dp[x][1] = n;
  f[x] = y;
  for (int i = h[x]; i; i = nx[i])
    if (t[i] != y) Dfs(t[i], x), c[x] = max(c[x], c[t[i]]);
  for (int j = 2; j < M; j++) {
    l = 0;
    for (int i = h[x]; i; i = nx[i])
      if (t[i] != y && dp[t[i]][j - 1]) a[++l] = dp[t[i]][j - 1];
    sort(a + 1, a + l + 1, Cmp);
    for (int k = l; k > 1; k--)
      if (a[k] >= k) {
        dp[x][j] = k;
        break;
      }
    if (dp[x][j]) g[dp[x][j]].push_back(pair<int, int>(x, j));
  }
  Ans += ++c[x];
}
void Update(int x, int y) {
  while (x) {
    if (cur[x] >= y) break;
    Res += y - cur[x];
    cur[x] = y;
    x = f[x];
  }
}
int main() {
  Read(n);
  for (int i = 1; i < n; i++) Read(x), Read(y), Add(x, y), Add(y, x);
  Dfs(1, 1);
  for (int i = 1; i <= n; i++) cur[i] = 1;
  Res = n;
  for (int k = n; k > 1; k--) {
    for (int j = 0; j < g[k].size(); j++) Update(g[k][j].first, g[k][j].second);
    Ans += Res;
  }
  cout << Ans << endl;
  return 0;
}
