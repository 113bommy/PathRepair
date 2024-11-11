#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
const int MAX = (int)1e5;
int n;
int a[N], cnt[N], cost[N], d[N];
inline void add(int u, int v, queue<int> &q, vector<int> &used) {
  d[v] = d[u] + 1;
  q.push(v);
  used.push_back(v);
}
void bfs(int src) {
  vector<int> used;
  queue<int> q;
  q.push(src);
  used.push_back(src);
  d[src] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = u * 2;
    if (v <= MAX && d[u] + 1 < d[v]) add(u, v, q, used);
    v = u / 2;
    if (v > 0 && d[u] + 1 < d[v]) add(u, v, q, used);
  }
  for (int i = 0; i < used.size(); i++) {
    cnt[used[i]]++;
    cost[used[i]] += d[used[i]];
    d[used[i]] = 1 << 30;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  fill(d, d + MAX + 1, 1 << 30);
  for (int i = 0; i < n; i++) bfs(a[i]);
  int ret = 1 << 30;
  for (int i = 1; i <= n; i++)
    if (cnt[i] == n) ret = min(ret, cost[i]);
  cout << ret << "\n";
}
