#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1000 * 1000 + 10;
const int maxn5 = 3 * 100 * 1000 + 10;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1LL * 2 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;
long long val[maxn5];
vector<int> adj[maxn5], hight[maxn5];
set<pair<int, long long> > q[maxn];
bool mark[maxn5];
int h[maxn5], st[maxn5], ft[maxn5], t = 0;
void dfs(int v) {
  hight[h[v]].push_back(v);
  st[v] = t++;
  mark[v] = true;
  for (auto u : adj[v])
    if (!mark[u]) {
      h[u] = h[v] + 1;
      dfs(u);
    }
  ft[v] = t++;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v, d, x;
    cin >> v >> d >> x;
    val[v] += x;
    if (d <= n) q[d + h[v] + 1].insert(make_pair(st[v], -x));
    if (d <= n) q[d + h[v] + 1].insert(make_pair(ft[v], x));
  }
  for (int i = 0; i < n; i++) {
    long long add = 0;
    auto it = q[i].begin();
    for (auto u : hight[i]) {
      while (it != q[i].end() and it->first <= st[u]) {
        add += it->second;
        it++;
      }
      val[u] += add;
      for (auto v : adj[u])
        if (h[v] > h[u]) val[v] += val[u];
    }
  }
  for (int i = 1; i <= n; i++) cout << val[i] << ' ';
  cout << endl;
  return 0;
}
