#include <bits/stdc++.h>
using namespace std;
long double PI = acosl(-1);
bool compare_int(int a, int b) { return (a > b); }
bool compare_string(string a, string b) { return a.size() < b.size(); }
bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return (a.second > b.second);
}
bool cmp(pair<string, int> x, pair<string, int> y) {
  return (x.second < y.second);
}
void NA() {
  printf("NO\n");
  exit(0);
}
void YA() {
  printf("YES\n");
  exit(0);
}
const int N = 2e5 + 5;
long long int dis[N], a[N];
vector<pair<int, long long int> > g[N];
int n, m;
void dijkstra() {
  priority_queue<pair<long long int, int> > pq;
  for (int i = 0; i < n; i++) {
    dis[i] = a[i];
    pq.push({-dis[i], i});
  }
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    int u = t.second;
    long long int d = -t.first;
    if (dis[u] < d) continue;
    for (auto it : g[u]) {
      int v = it.first;
      long long int w = it.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pq.push({-dis[v], v});
      }
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int u, v, w;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld %lld", &u, &v, &w);
    u--, v--;
    w *= 2;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  dijkstra();
  for (int i = 0; i < n; i++) printf("%lld ", dis[i]);
}
