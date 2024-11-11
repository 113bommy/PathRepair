#include <bits/stdc++.h>
using namespace std;
const int N = 255003;
long long n, L, S;
long long v[N], p[N], sum[N];
int ans;
vector<int> e[N];
int calcu(int h) {
  int l = max(1LL, h - L + 1), r = h, m;
  while (l <= r) {
    m = l + r >> 1;
    if (sum[h] - sum[m] > S)
      l = m + 1;
    else
      r = m - 1;
  }
  if (r < h) return r + 1;
  return r;
}
void dfs(int s, int h) {
  sum[h] = sum[h - 1] + v[s];
  if (e[s].size()) ans += e[s].size() - 1;
  int res = h + 3;
  for (int i = 0; i < e[s].size(); ++i) {
    int u = e[s][i];
    dfs(u, h + 1);
    res = min(1LL * res, p[u]);
  }
  if (res <= h)
    p[s] = res;
  else {
    if (e[s].size()) ++ans;
    p[s] = calcu(h);
  }
}
int main() {
  cin >> n >> L >> S;
  int x;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    if (v[i] > S) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    e[x].push_back(i);
  }
  dfs(1, 1);
  cout << ans + 1;
  return 0;
}
