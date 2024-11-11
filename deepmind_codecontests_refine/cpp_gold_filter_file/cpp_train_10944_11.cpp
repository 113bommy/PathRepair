#include <bits/stdc++.h>
using namespace std;
long long encode(long long w, long long d) { return w * 10000000LL + d; }
pair<long long, long long> decode(long long e) {
  return make_pair(e / 10000000LL, e % 10000000LL);
}
map<long long, int> tl[100100];
long long go[100100];
long long dp[100100][250];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= n; i++) go[i] = encode(0, i + 1);
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = (1LL << 60LL);
  for (int i = 0; i < k; i++) {
    int s, t, d, w;
    scanf("%d%d%d%d", &s, &t, &d, &w);
    ++t;
    ++d;
    long long v = encode(w, d);
    if (tl[s].find(v) == tl[s].end()) tl[s][v] = 0;
    if (tl[t].find(v) == tl[t].end()) tl[t][v] = 0;
    tl[s][v]++;
    tl[t][v]--;
  }
  map<long long, int> cur;
  for (int i = 1; i <= n; i++) {
    for (auto &it : tl[i]) {
      auto key = it.first;
      auto val = it.second;
      if (cur.find(key) == cur.end())
        cur[key] = val;
      else
        cur[key] += val;
      if (cur[key] == 0) cur.erase(key);
    }
    if (!cur.empty()) go[i] = cur.rbegin()->first;
  }
  dp[1][m] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      auto g = decode(go[i]);
      auto nxt = g.second;
      auto cost = g.first;
      dp[nxt][j] = min(dp[nxt][j], dp[i][j] + cost);
      if (j) dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
    }
  }
  long long ans = (1LL << 60LL);
  for (int j = 0; j <= m; j++) ans = min(ans, dp[n + 1][j]);
  printf("%lld\n", ans);
}
