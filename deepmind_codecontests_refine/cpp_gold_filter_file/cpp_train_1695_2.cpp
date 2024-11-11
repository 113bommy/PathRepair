#include <bits/stdc++.h>
using namespace std;
int N, M, last;
long long dp[2005][2 * 2005][2];
bool visited[2005];
vector<int> edges[2005], a;
map<int, int> cnt;
int dfs(int v) {
  visited[v] = true;
  for (int u : edges[v]) {
    if (visited[u]) continue;
    return 1 + dfs(u);
  }
  return 1;
}
long long solve(int pos, int dif, bool takeAll) {
  if (pos == a.size()) {
    if (takeAll) return (dif == max(0, last - 1));
    return dif < last - 1;
  }
  long long& res = dp[pos][dif][takeAll];
  if (res != -1) return dp[pos][dif][takeAll];
  res = 0;
  res += solve(pos + 1, dif + a[pos], takeAll);
  res += solve(pos + 1, abs(dif - a[pos]), takeAll);
  if (!takeAll) {
    res += solve(pos + 1, dif, takeAll);
  }
  res %= 1000000007;
  return res;
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  visited[0] = true;
  for (int v : edges[0]) {
    if (visited[v]) continue;
    cnt[dfs(v) + 1]++;
  }
  long long ans = 0;
  for (auto itr : cnt) {
    memset(dp, -1, sizeof(dp));
    a.clear();
    last = itr.first;
    for (auto itr2 : cnt) {
      for (int i = 0; i < itr2.second - (itr.first == itr2.first); ++i) {
        a.push_back(itr2.first);
      }
    }
    ans += 2ll * (itr.second * (solve(0, 0, true) + solve(0, 0, false))) %
           1000000007;
    ans %= 1000000007;
  }
  memset(dp, -1, sizeof(dp));
  a.clear();
  for (auto itr : cnt) {
    for (int i = 0; i < itr.second; ++i) {
      a.push_back(itr.first);
    }
  }
  last = 0;
  ans = (ans + solve(0, 0, true)) % 1000000007;
  cout << ans << endl;
  return 0;
}
