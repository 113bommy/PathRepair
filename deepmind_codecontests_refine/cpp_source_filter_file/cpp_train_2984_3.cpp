#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 100;
const int inf_int = 1e9 + 100;
const long long inf_ll = 1e18;
const double PI = 3.1415926535898;
bool debug = 0;
vector<int> g[MAXN];
bool used[MAXN];
int comp = 0;
void dfs(int v) {
  if (used[v]) return;
  used[v] = 1;
  comp++;
  for (int to : g[v]) {
    dfs(to);
  }
}
int cnt[MAXN];
long long dp[2][MAXN];
pair<long long, int> q[MAXN];
int head = 0, top = 0;
inline void add(long long val, int pos) {
  while (head < top && q[top].first >= val) {
    top--;
  }
  q[top++] = {val, pos};
}
inline long long get() { return q[head].first; }
inline void rem(int pos) {
  if (head < top && q[head].second <= pos) head++;
}
inline void del() { head = top = 0; }
vector<int> happy;
void fun(int i, int val) {
  if (i > 6) return;
  if (val > 0) happy.push_back(val);
  fun(i + 1, val * 10 + 4);
  fun(i + 1, val * 10 + 7);
}
void solve() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      comp = 0;
      dfs(i);
      cnt[comp]++;
    }
  }
  fill(dp[0], dp[0] + MAXN, inf_int);
  fill(dp[1], dp[1] + MAXN, inf_int);
  dp[0][0] = 0;
  dp[1][0] = 0;
  int prev = 0;
  int cur = 1;
  for (int val = 1; val <= n; ++val) {
    if (!cnt[val]) {
      continue;
    }
    for (int st = 0; st < val; ++st) {
      for (int i = st; i <= n; i = i + val) {
        if (i - 1ll * cnt[val] * val - 1 >= 0) rem(i - val * cnt[val] - 1);
        dp[cur][i] = dp[prev][i];
        if (i >= val) {
          long long x = get();
          x = (x + i) / val;
          dp[cur][i] = min(dp[prev][i], x);
        }
        add(dp[prev][i] * val - i, i);
      }
      del();
    }
    cur ^= 1;
    prev ^= 1;
  }
  fun(0, 0);
  long long ans = inf_int;
  for (int v : happy) {
    if (v <= n) {
      ans = min(ans, dp[prev][v]);
    }
  }
  if (ans > n) {
    cout << -1;
  } else {
    cout << ans - 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
