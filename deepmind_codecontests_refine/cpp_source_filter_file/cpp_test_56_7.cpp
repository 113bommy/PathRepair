#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int trans(string s) {
  if (s == "white") return 0;
  if (s == "yellow") return 1;
  if (s == "green") return 2;
  if (s == "blue") return 3;
  if (s == "red") return 4;
  if (s == "orange") return 5;
}
int K, N;
set<long long> marked;
map<long long, int> color;
map<long long, vector<long long> > dp;
long long pw(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % MOD)
    if (y & 1) ret = ret * x % MOD;
  return ret;
}
void inc(long long& x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void dfs(int v, long long tot) {
  dp[v].resize(6, 0);
  if (marked.count(v) == 0) {
    for (int i = 0; i < (int)(6); ++i) dp[v][i] = pw(4, tot - 1);
    return;
  }
  if (tot == 1) {
    int c = color[v];
    dp[v][c] = 1;
    return;
  }
  dfs(v << 1, (tot - 1) / 2);
  dfs(v << 1 | 1, (tot - 1) / 2);
  vector<long long>&dpl = dp[v << 1], &dpr = dp[v << 1 | 1];
  vector<long long>& dpm = dp[v];
  if (color.count(v)) {
    int c = color[v];
    long long L = 0, R = 0;
    for (int i = 0; i < (int)(6); ++i) {
      if (i == c || i == (c ^ 1)) continue;
      inc(L, dpl[i]), inc(R, dpr[i]);
    }
    dpm[c] = L * R % MOD;
  } else {
    for (int i = 0; i < (int)(6); ++i) {
      long long L = 0, R = 0;
      for (int j = 0; j < (int)(6); ++j) {
        if (j == i || j == (i ^ 1)) continue;
        inc(L, dpl[j]), inc(R, dpr[j]);
      }
      dpm[i] = L * R % MOD;
    }
  }
}
int main() {
  scanf("%d%d", &K, &N);
  for (int i = 0; i < (int)(N); ++i) {
    long long v;
    string s;
    scanf("%lld", &v);
    cin >> s;
    color[v] = trans(s);
    while (v) {
      marked.insert(v);
      v >>= 1;
    }
  }
  dfs(1, (1ll << K) - 1);
  long long sum = 0;
  for (int i = 0; i < (int)(6); ++i) inc(sum, dp[1][i]);
  printf("%lld\n", sum);
  return 0;
}
