#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  return (b < a) ? (a = b, 1) : 0;
}
using namespace std;
using ll = long long;
const int inf = 1 << 20;
const int nmax = 10010;
bool a[nmax], b[nmax];
int c[110];
vector<int> graph[nmax];
vector<int> idx;
int dist[nmax];
int cost[25][25];
void bfs(int n) {
  for (int i = int(0); i < int(n); ++i) {
    fill(dist, dist + nmax, inf);
    queue<int> q;
    dist[idx[i]] = 0, q.push(idx[i]);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &v2 : graph[v])
        if (chmin(dist[v2], dist[v] + 1)) q.push(v2);
    }
    for (int j = int(0); j < int(n); ++j) cost[i][j] = dist[idx[j]];
  }
}
int dp[1 << 20];
int main(void) {
  int n, k, l;
  cin >> n >> k >> l;
  for (int i = int(0); i < int(k); ++i) {
    int in;
    cin >> in;
    a[in] = 1;
  }
  for (int i = int(0); i < int(n + 1); ++i)
    if (a[i] ^ a[i + 1]) idx.push_back(i);
  for (int i = int(0); i < int(l); ++i) cin >> c[i];
  for (int i = int(0); i < int(n); ++i) {
    for (int j = int(0); j < int(l); ++j)
      if (i + c[j] <= n) {
        graph[i].push_back(i + c[j]);
        graph[i + c[j]].push_back(i);
      }
  }
  int m = idx.size();
  bfs(m);
  fill(dp, dp + (1LL << m), inf), dp[0] = 0;
  for (int mask = int(0); mask < int((1LL << m)); ++mask)
    for (int j = int(0); j < int(m); ++j)
      for (int i = int(0); i < int(j); ++i) {
        if ((mask & (1LL << i)) == 0) continue;
        if ((mask & (1LL << j)) == 0) continue;
        int pmask = mask ^ (1LL << i) ^ (1LL << j);
        chmin(dp[mask], dp[pmask] + cost[i][j]);
      }
  int ans = dp[(1LL << m) - 1];
  if (ans >= inf)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
