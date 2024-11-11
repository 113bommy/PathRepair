#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)3e5 + 10;
const int INF = (int)1e9 + 7;
const long long LINF = (long long)1e18 + 10;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0);
int n, m;
int a[MXN], b[MXN], c[MXN];
int f[MXN];
bool used[MXN];
int ans[MXN];
vector<pair<int, int> > g[MXN];
void bfs() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto it : g[v]) {
      if (used[it.second]) continue;
      used[it.second] = true;
      ans[it.second] = (a[it.second] == v ? 0 : 1);
      f[it.first] -= c[it.second];
      if (!f[it.first]) {
        q.push(it.first);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    f[a[i]] += c[i];
    f[b[i]] += c[i];
    g[a[i]].push_back(make_pair(b[i], i));
    g[b[i]].push_back(make_pair(a[i], i));
  }
  for (int i = 2; i < n; ++i) {
    f[i] /= 2;
  }
  bfs();
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
