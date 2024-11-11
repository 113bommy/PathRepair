#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
vector<int> g[100010];
int v[100010], d[100010], ans[100010];
priority_queue<int> q;
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    d[b]++;
    g[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) sort((g[i]).begin(), (g[i]).end());
  for (int i = 1; i <= n; i++)
    if (!d[i]) {
      q.push(-i);
      v[i] = 1;
    }
  int cnt = 1;
  while (!q.empty()) {
    int x = -q.top();
    q.pop();
    ans[x] = cnt++;
    for (auto i : g[x]) {
      if (v[i]) continue;
      d[i]--;
      if (!d[i]) {
        q.push(-i);
        v[i] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
