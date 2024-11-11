#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
vector<int> adj[100010];
long long a[100010], b[100010], c[100010];
int n;
void dfs(int cur, int from) {
  for (int i = 0; i < adj[cur].size(); i++) {
    int k = adj[cur][i];
    if (from == k) continue;
    dfs(k, cur);
    a[cur] = max(a[cur], a[k]);
    b[cur] = max(b[cur], b[k]);
  }
  c[cur] += a[cur];
  c[cur] -= b[cur];
  if (c[cur] < 0)
    a[cur] -= c[cur];
  else
    b[cur] += c[cur];
}
int main() {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(0));
  memset(c, 0, sizeof(0));
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) cin >> c[i];
  dfs(1, 0);
  cout << a[1] + b[1] << endl;
  return 0;
}
