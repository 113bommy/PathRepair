#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
vector<int> v[maxn], s[maxn];
bool mark[maxn], lucky[maxn];
long long dp[maxn], n, m;
long long siz;
long long ans = 1e6;
void dfs(long long i) {
  siz++;
  mark[i] = 1;
  for (long long y = 0; y < v[i].size(); y++) {
    long long x = v[i][y];
    if (!mark[x]) dfs(x);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  lucky[0] = 1;
  for (int i = 1; i <= n; i++) {
    lucky[i] = (lucky[i / 10] && (i % 10 == 4 || i % 10 == 7));
  }
  while (m--) {
    long long i, j;
    cin >> i >> j;
    v[i].push_back(j);
    v[j].push_back(i);
  }
  for (long long y = 1; y <= n; y++) {
    if (!mark[y]) {
      siz = 0, dfs(y), s[siz].push_back(1);
    }
  }
  for (long long y = 1; y <= n; y++) {
    sort(s[y].begin(), s[y].end());
    while (s[y].size() > 2) {
      long long i = s[y][s[y].size() - 1];
      i += s[y][s[y].size() - 2];
      s[y].pop_back();
      s[y].pop_back();
      s[y * 2].push_back(i);
    }
  }
  for (int i = 0; i <= n; i++) dp[i] = 1e6;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (long long y = 0; y < s[i].size(); y++) {
      long long x = s[i][y];
      for (long long j = n; j >= i; j--) {
        dp[j] = min(dp[j], dp[j - i] + x);
        if (lucky[j]) ans = min(ans, dp[j] - 1);
      }
    }
  }
  if (ans >= 1e6 - 10) ans = -1;
  cout << ans;
}
