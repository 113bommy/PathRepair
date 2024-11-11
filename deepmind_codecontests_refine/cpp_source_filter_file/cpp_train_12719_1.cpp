#include <bits/stdc++.h>
using namespace std;
const int N = 500;
const int oo = 1e9 + 5;
int du[] = {-1, 0, 0, 1};
int dv[] = {0, -1, 1, 0};
const long long mod = 1e9 + 7;
long long sqr(long long x) { return x * x; }
int n, dem, res = oo, lv[N + 5], trace[N + 5];
long long a[100005];
vector<int> g[N + 5];
void bfs(int u1) {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    lv[i] = 0;
    trace[i] = 0;
  }
  lv[u1] = 1;
  trace[u1] = u1;
  q.push(u1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v == trace[u]) continue;
      if (lv[v]) {
        res = min(res, lv[v] - lv[u1] + lv[u] - lv[u1] + 1);
        continue;
      }
      lv[v] = lv[u] + 1;
      trace[v] = u;
      q.push(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp) a[++dem] = tmp;
  }
  n = dem;
  if (n > 130) {
    cout << 3;
    return 0;
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] & a[j]) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
  for (int i = 1; i <= n; i++) bfs(i);
  if (res >= oo)
    cout << -1;
  else
    cout << res;
  return 0;
}
