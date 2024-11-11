#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = (long long)2e18;
long long add(long long x, long long y) { return min(x + y, INF); }
const int N = 2010;
const int M = (int)4e6 + 7;
char s[N];
int n, m;
long long k;
int lcp[N][N];
pair<int, int> ord[M];
int sz;
int g[N];
long long dp[N][N];
bool cmp(const pair<int, int> &v, const pair<int, int> &u) {
  int x = lcp[v.first][u.first];
  if (x >= v.second || x >= u.second) return v.second < u.second;
  return s[v.first + x] < s[u.first + x];
}
long long solve(int rr) {
  for (int i = 0; i <= n; i++) g[i] = n + 1;
  for (int i = sz - 1; i >= rr; i--) {
    g[ord[i].first] = ord[i].second;
  }
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  dp[0][1] = -1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (j > 0) dp[i][j] = add(dp[i][j], dp[i][j - 1]);
      dp[i + 1][j + g[j]] = add(dp[i + 1][j + g[j]], dp[i][j]);
    }
  long long ans = 0;
  for (int i = 0; i <= n; i++) ans = add(ans, dp[m][i]);
  return ans;
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  scanf("%s", s);
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--) {
      if (s[i] != s[j]) {
        lcp[i][j] = 0;
      } else {
        lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= n; j++) ord[sz++] = make_pair(i, j - i);
  sort(ord, ord + sz, cmp);
  int l = 0, r = sz;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (solve(mid) >= k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  for (int i = 0; i < ord[l].second; i++) printf("%c", s[ord[l].first + i]);
  printf("\n");
  return 0;
}
