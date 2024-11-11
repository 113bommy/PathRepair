#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, maxx = 1 << 22, inf = 1e9 + 10;
int n, k, lg = 20, Min[maxx];
void smin(int &a, int b) { a = min(a, b); }
bool bit(int a, int i) { return (a >> i) & 1; }
int toint(char s[]) {
  int ans = 0;
  for (int i = int(0); i < int(lg); i++) {
    ans <<= 1;
    ans += s[i] - '0';
  }
  return ans;
}
int com(int x, int y) {
  int ans = 0;
  for (int step = int(0); step < int(lg + 1); step++) {
    int a = x % (1 << step), b = y >> (lg - step);
    if (a == b) ans = step;
  }
  return ans;
}
int c[maxn], g[maxn], dp[maxn], A[maxn];
int32_t main() {
  scanf("%d", &n);
  for (int i = int(0); i < int(n); i++) {
    char c[lg];
    scanf("%s", c);
    lg = strlen(c);
    A[i] = toint(c);
  }
  for (int i = int(1); i < int(n); i++) {
    c[i] = com(A[i - 1], A[i]);
  }
  for (int i = int(1); i < int(n + 1); i++) {
    g[i] = g[i - 1] + lg - c[i - 1];
  }
  dp[0] = lg;
  dp[1] = 2 * lg;
  fill(Min, Min + maxx, inf);
  for (int i = int(2); i < int(n); i++) {
    dp[i] = dp[i - 1] + lg - com(A[i - 2], A[i]);
    smin(dp[i], g[i] + lg);
    int pref = 1;
    for (int j = int(0); j < int(lg); j++) {
      smin(dp[i], g[i] + lg - j + Min[pref]);
      pref <<= 1;
      pref += bit(A[i], lg - j - 1);
    }
    int suf = 0;
    for (int j = int(0); j < int(lg); j++) {
      int sf = suf + (1 << j);
      smin(Min[sf], dp[i - 1] - g[i]);
      suf += (1 << j) * bit(A[i - 2], j);
    }
  }
  int ans = inf;
  for (int i = int(0); i < int(n); i++) {
    smin(ans, g[n] - g[i + 1] + dp[i]);
  }
  printf("%d\n", ans);
}
