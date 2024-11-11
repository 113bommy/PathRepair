#include <bits/stdc++.h>
const long long MAXN = 1e6 + 1;
const long long INF = 1e9;
using namespace std;
std::vector<int> d(MAXN, INF);
std::vector<std::vector<int> > hz(MAXN);
std::pair<int, int> ind[MAXN];
std::vector<std::vector<int> > G(MAXN);
void next(vector<int>& a) {
  int i = a.size() - 1;
  while (a[i] == hz[i].size()) {
    a[i--] = 1;
  }
  a[i] += 1;
}
int main() {
  int N, M, K;
  std::cin >> N >> M >> K;
  for (int i = 1; i <= M; i++) {
    int u, v;
    std::cin >> u >> v;
    ind[i] = std::make_pair(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  std::queue<int> Q;
  d[1] = 0;
  Q.push(1);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int to = G[u][i];
      if (d[to] == INF) {
        d[to] = d[u] + 1;
        Q.push(to);
      }
    }
  }
  for (int i = 1; i <= M; i++) {
    int u = ind[i].first;
    int v = ind[i].second;
    if (d[u] + 1 == d[v]) {
      hz[v].push_back(i);
    }
    if (d[v] + 1 == d[u]) {
      hz[u].push_back(i);
    }
  }
  int cnt = 1;
  for (int i = 2; i <= N; i++) {
    int cnt1 = hz[i].size();
    cnt *= cnt1;
    if (cnt > K) break;
  }
  vector<int> deg(N + 1, 1);
  cnt = min(K, cnt);
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    string ans = "";
    for (int j = 0; j < M; j++) {
      ans += "0";
    }
    for (int j = 2; j <= N; j++) {
      ans[hz[j][deg[j] - 1] - 1] = '1';
    }
    cout << ans << endl;
    next(deg);
  }
  return 0;
}
