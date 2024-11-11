#include <bits/stdc++.h>
using namespace std;
int fr[2005], to[2005];
int n;
int dist(int a, int b) {
  if (a == 0 || b == 0) return 0;
  return abs(b - a);
}
map<long long, int> dp[2001];
long long p[10];
int rec(int pos, int a, int b, int c, int d, int f) {
  if (pos == n) {
    if (!a && !b && !c && !d) return 0;
  }
  f++;
  long long state = p[a] + p[b] + p[c] + p[d] + p[10] * f;
  if (dp[pos].find(state) != dp[pos].end()) return dp[pos][state];
  int &ret = dp[pos][state];
  ret = 1000000007;
  if (pos < n) {
    if (a == 0) {
      int _a = a, _b = b, _c = c, _d = d;
      ret = min(ret, dist(fr[pos + 1], f) + rec(pos + 1, to[pos + 1], _b, _c,
                                                _d, fr[pos + 1] - 1));
    } else if (b == 0) {
      int _a = a, _b = b, _c = c, _d = d;
      ret = min(ret, dist(fr[pos + 1], f) + rec(pos + 1, _a, to[pos + 1], _c,
                                                _d, fr[pos + 1] - 1));
    } else if (c == 0) {
      int _a = a, _b = b, _c = c, _d = d;
      ret = min(ret, dist(fr[pos + 1], f) + rec(pos + 1, _a, _b, to[pos + 1],
                                                _d, fr[pos + 1] - 1));
    } else if (d == 0) {
      int _a = a, _b = b, _c = c, _d = d;
      ret = min(ret, dist(fr[pos + 1], f) + rec(pos + 1, _a, _b, _c,
                                                to[pos + 1], fr[pos + 1] - 1));
    }
  }
  if (a) ret = min(ret, dist(f, a) + rec(pos, 0, b, c, d, a - 1));
  if (b) ret = min(ret, dist(f, b) + rec(pos, a, 0, c, d, b - 1));
  if (c) ret = min(ret, dist(f, c) + rec(pos, a, b, 0, d, c - 1));
  if (d) ret = min(ret, dist(f, d) + rec(pos, a, b, c, 0, d - 1));
  return ret;
}
int main() {
  p[0] = 1;
  for (int i = 1; i < 11; i++) p[i] = 457ll * p[i - 1];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", &fr[i], &to[i]);
  int ans = 0;
  for (int i = 1; i <= 1; i++) {
    ans = max(ans, dist(1, fr[i]) + rec(1, to[i], 0, 0, 0, fr[i] - 1));
  }
  printf("%d\n", ans + 2 * n);
  return 0;
}
