#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> make(int x, int y) { return pair<int, int>(x, y); }
map<pair<int, int>, int> dp[1 << 17];
int n, r[20], b[20], c[20];
void UMAX(int &x, int y) {
  if (x < y) x = y;
}
void UMIN(int &x, int y) {
  if (x > y) x = y;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; i++) {
    char ch[2];
    scanf("%s %d%d", ch, &r[i], &b[i]);
    if (ch[0] == 'R') c[i] = 1;
  }
  dp[0][make(0, 0)] = 0;
  map<pair<int, int>, int>::iterator it;
  for (int x = 0; x < (1 << n); x++) {
    int re = 0, bl = 0;
    for (int j = 0; j < n; j++)
      if ((x >> j) & 1) c[j] ? ++re : ++bl;
    for (int j = 0; j < n; j++) {
      if (x & (1 << j)) continue;
      for (it = dp[x].begin(); it != dp[x].end(); it++) {
        int nxt = (1 << j) | x;
        int cnt = 0;
        int rv = max(r[j] - re, 0), bv = max(b[j] - bl, 0);
        if (it->first.first < rv) UMAX(cnt, rv - it->first.first);
        if (it->first.second < bv) UMAX(cnt, rv - it->first.second);
        pair<int, int> nxt_s = pair<int, int>(it->first.first + cnt - rv,
                                              it->first.second + cnt - bv);
        if (dp[nxt].count(nxt_s) == 0) dp[nxt][nxt_s] = INT_MAX;
        UMIN(dp[nxt][nxt_s], cnt + it->second + 1);
      }
    }
  }
  int ans = INT_MAX;
  for (it = dp[(1 << n) - 1].begin(); it != dp[(1 << n) - 1].end(); it++) {
    UMIN(ans, it->second);
  }
  printf("%d\n", ans);
  return 0;
}
