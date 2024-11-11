#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 4e5 + 5;
multiset<int> st;
vector<int> g[2003];
int vis[2003];
map<int, int> mp;
vector<int> v;
long long dp[2005][4005][2];
int c;
int dfs(int now, int pre) {
  vis[now] = 1;
  if (g[now][0] == g[now][1]) {
    return 2;
  }
  if (now == 1) {
    return 1;
  }
  for (auto &i : g[now]) {
    if (i == pre) continue;
    return dfs(i, now) + 1;
  }
}
long long solve(int pos, int dif, int flag) {
  if (dif < 0 || dif > 4000) {
    return 0;
  }
  if (~dp[pos][dif][flag]) {
    return dp[pos][dif][flag];
  }
  if (pos == v.size()) {
    if (flag) {
      return dp[pos][dif][flag] = (abs(dif - 2000) == c - 1);
    } else {
      return dp[pos][dif][flag] = (abs(dif - 2000) < c - 1);
    }
  }
  long long sum = 0;
  sum += solve(pos + 1, dif - v[pos], flag);
  sum += solve(pos + 1, dif + v[pos], flag);
  if (!flag) {
    sum += solve(pos + 1, dif, flag);
  }
  sum %= mod;
  return dp[pos][dif][flag] = sum;
}
long long solve(int flag, int cycle) {
  c = cycle;
  v.clear();
  for (auto &i : st) {
    v.push_back(i);
  }
  long long ret = 0;
  memset(dp, -1, sizeof(dp));
  if (!flag) {
    ret += solve(0, 2000, 0);
    ret %= mod;
  }
  ret += solve(0, 2000, 1);
  ret %= mod;
  return ret;
}
void go() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (auto &i : g[1]) {
    if (vis[i]) continue;
    int d = dfs(i, 1);
    mp[d]++;
    st.insert(d);
  }
  long long ans = 0;
  for (auto &i : mp) {
    st.erase(st.find(i.first));
    ans += solve(0, i.first) * 2LL * i.second % mod;
    ans %= mod;
    st.insert(i.first);
  }
  ans += solve(1, 1);
  ans %= mod;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    go();
  }
}
