#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> v[100005];
vector<int> graph[100005];
bool ok(int lim) {
  for (int i = 1; i <= n; i++) graph[i].clear();
  vector<int> in(n + 1, 0);
  for (int i = 1; i <= lim; i++) {
    graph[v[i].first].push_back(v[i].second);
    in[v[i].second]++;
  }
  queue<int> que;
  for (int i = 1; i <= n; i++)
    if (!in[i]) que.push(i);
  while (!que.empty()) {
    if (que.size() >= 2) return false;
    int now = que.front();
    que.pop();
    for (int i = 0; i < graph[now].size(); i++) {
      int next = graph[now][i];
      if (--in[next]) que.push(next);
    }
  }
  return true;
}
int find() {
  int L = 1, R = m, ret = -1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (ok(mid))
      ret = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  return ret;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i].first >> v[i].second;
  }
  cout << find() << endl;
}
