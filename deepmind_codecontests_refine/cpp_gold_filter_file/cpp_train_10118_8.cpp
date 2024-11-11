#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,sse")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long maxn = 1e6;
vector<long long> g[maxn];
vector<long long> cv;
long long dp[maxn];
long long ans = 0;
void dfs(long long x) {
  if (g[x].size() == 0) {
    dp[x] = 1;
    return;
  }
  dp[x] = 1;
  for (long long i = 0; i < g[x].size(); i++) {
    long long to = g[x][i];
    dfs(to);
    dp[x] = max(dp[x], dp[to] + 1);
  }
}
bool cmp(long long x, long long y) { return dp[x] < dp[y]; }
void dfs2(long long x) {
  cv.push_back(x);
  sort(g[x].begin(), g[x].end(), cmp);
  for (long long i = 0; i < g[x].size(); i++) {
    long long to = g[x][i];
    dfs2(to);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long p[n];
  p[0] = -1;
  for (long long i = 1; i < n; i++) {
    long long pr;
    cin >> pr;
    p[i] = pr;
    g[pr].push_back(i);
  }
  dfs(0);
  dfs2(0);
  for (long long i = 0; i < n; i++) {
    cout << cv[i] << ' ';
  }
  vector<long long> dst;
  stack<long long> st;
  st.push(0);
  for (long long i = 1; i < n; i++) {
    while (st.top() != p[cv[i]]) {
      dst.push_back(cv[i]);
      st.pop();
    }
    st.push(cv[i]);
  }
  cout << '\n' << dst.size() << '\n';
  for (long long i = 0; i < dst.size(); i++) cout << dst[i] << ' ';
  return 0;
}
