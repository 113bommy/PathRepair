#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAXN = 2000005;
int v[MAXN];
int c[25];
char vis[MAXN];
int n, m, d;
void dfs(int v) {
  vis[v] = 1;
  for (int i = 0; i < m; ++i) {
    if (!(v & (1 << i))) continue;
    int k = v ^ (1 << i);
    if (vis[k]) continue;
    dfs(k);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> m >> d) {
    vector<int> vec;
    for (int i = 0; i < m; ++i) {
      int x, t;
      cin >> t;
      for (int j = 0; j < t; ++j) {
        cin >> x;
        v[x - 1] = i;
      }
    }
    memset(c, 0, sizeof c);
    int mask = 0;
    for (int i = 0; i < d; ++i) c[v[i]]++;
    for (int i = 0; i < m; ++i)
      if (!c[i]) mask |= 1 << i;
    vec.push_back(mask);
    for (int i = d; i < n; ++i) {
      c[v[i - d]]--;
      if (!c[v[i - d]]) mask |= 1 << v[i - d];
      if (!c[v[i]]) mask ^= 1 << v[i];
      c[v[i]]++;
      vec.push_back(mask);
    }
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < (int)vec.size(); ++i) {
      if (vis[vec[i]]) continue;
      dfs(vec[i]);
    }
    int res = m, db = 0;
    for (int i = 0; i < 1 << m; ++i) {
      int x = __builtin_popcount(i);
      if (vis[i]) continue;
      if (x < res) db = i;
      res = min(x, res);
    }
    cout << res << endl;
  }
}
