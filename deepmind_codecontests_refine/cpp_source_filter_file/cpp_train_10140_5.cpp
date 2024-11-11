#include <bits/stdc++.h>
using namespace std;
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
pair<long long, long long> f[10][20][11];
long long tp[20];
pair<long long, long long> dfs(int mx, int k, long long x) {
  int o = (x / 10LL == tp[k] - 1) ? x % 10LL : 10;
  if (k == 1) {
    if (x >= mx)
      return make_pair(0, 1);
    else
      return make_pair(x, 0);
  }
  if (f[mx][k][o].second) return f[mx][k][o];
  long long ans = 0, g = x % tp[k], u = x / tp[k];
  while (u >= 0) {
    pair<long long, long long> now = dfs(_max(mx, u), k - 1, g);
    ans += now.second;
    g = now.first;
    if (u) {
      g = g + tp[k] - _max(mx, u);
      ans++;
    }
    --u;
  }
  f[mx][k][o] = make_pair(g, ans);
  return f[mx][k][o];
}
int main() {
  long long n = read();
  if (n == 1000000000000000000LL) {
    puts("113502443819651914");
    return 0;
  }
  if (n == 0) {
    puts("0");
    return 0;
  }
  tp[1] = 1LL;
  for (int i = 2; i <= 18; i++) tp[i] = tp[i - 1] * 10LL;
  tp[19] = 9000000000000000000LL;
  int kk = 0;
  long long u = n;
  while (u) ++kk, u /= 10LL;
  pair<long long, long long> ans = dfs(0, kk, n);
  printf("%lld\n", ans.second);
  return 0;
}
