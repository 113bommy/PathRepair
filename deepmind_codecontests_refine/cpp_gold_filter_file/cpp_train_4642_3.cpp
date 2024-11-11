#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
vector<int> v[200500], ans;
int n, m, pre[200500], ban[200500], f[200500];
int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
void get(int x, int y) {
  if (x == y) return;
  if (!f[x]) return;
  if (f[x] < f[y] + v[x].size()) f[x] = f[y] + v[x].size(), pre[x] = y;
}
void solve(int x) {
  if (pre[x]) solve(pre[x]);
  for (int i = 0; i <= v[x].size() - 1; i++) ans.push_back(v[x][i]);
}
int exgcd(int a, int b, int &x, int &y) {
  int d = 0;
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    ban[x] = 1;
  }
  for (int i = 0; i <= m - 1; i++)
    if (!ban[i]) v[gcd(m, i)].push_back(i);
  for (int i = 1; i <= m; i++) f[i] = v[i].size();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= (int)sqrt(m); j++)
      if (i % j == 0) {
        get(i, j);
        if (j != 1) get(i, i / j);
      }
  }
  int mx = 0, mxid;
  for (int i = 1; i <= m; i++)
    if (f[i] > mx) mx = f[i], mxid = i;
  solve(mxid);
  printf("%d\n", ans.size());
  if (ans.size()) printf("%d ", ans[0]);
  for (int i = 1; i <= ans.size() - 1; i++) {
    int x, y, d;
    d = exgcd(ans[i - 1], m, x, y);
    printf("%lld ", (1LL * x * ans[i] / d % m + m) % m);
  }
  return 0;
}
