#include <bits/stdc++.h>
using namespace std;
int n, m, k, second, d[100005][105];
bool visit[100005];
vector<int> v[100005], src[105];
void bfs(int r) {
  queue<int> q;
  memset(visit, false, n + 1);
  for (int e : src[r]) {
    q.push(e);
    visit[e] = true;
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nei : v[cur])
      if (!visit[nei]) {
        d[nei][r] = d[cur][r] + 1;
        visit[nei] = true;
        q.push(nei);
      }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k >> second;
  int a, b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) d[i][j] = INT_MAX;
    cin >> a;
    src[a].push_back(i);
    d[i][a] = 0;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= k; i++) bfs(i);
  for (int i = 1; i <= n; i++) {
    sort(d[i] + 1, d[i] + k + 1);
    int Sum = 0;
    for (int j = 1; j <= second; j++) Sum += d[i][j];
    cout << Sum << ' ';
  }
  return 0;
}
