#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 200100;
int n, m, q;
int u[M], v[M];
int dp[N], ans[M];
void calc(vector<pair<pair<int, int>, pair<int, int> > >& vec, int _) {
  for (int i = 1; i <= n; i++) dp[i] = n + 1;
  for (int i = m; i >= 1; i--) {
    dp[_] = i;
    if (dp[u[i]] < dp[v[i]])
      dp[v[i]] = dp[u[i]];
    else
      dp[u[i]] = dp[v[i]];
    while (vec.size()) {
      int l = vec.back().first.first, r = vec.back().first.second;
      int s = vec.back().second.first, j = vec.back().second.second;
      if (l != i) break;
      ans[j] = dp[s] <= r;
      vec.pop_back();
    }
  }
}
vector<pair<pair<int, int>, pair<int, int> > > vec[N];
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) scanf("%d%d", u + i, v + i);
  for (int i = 1; i <= q; i++) {
    int l, r, s, t;
    scanf("%d%d%d%d", &l, &r, &s, &t);
    vec[t].push_back(pair<pair<int, int>, pair<int, int> >(
        pair<int, int>(l, r), pair<int, int>(s, i)));
  }
  for (int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
  for (int i = 1; i <= n; i++) calc(vec[i], i);
  for (int i = 1; i <= q; i++) puts(ans[i] ? "Yes" : "No");
  return 0;
}
