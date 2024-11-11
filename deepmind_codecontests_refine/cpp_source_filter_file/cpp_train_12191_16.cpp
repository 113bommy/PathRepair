#include <bits/stdc++.h>
using namespace std;
const int K = 1e7 + 5, N = 1e6 + 5, M = 1400 + 5;
int dis[M][M], dist[M][M], ans[M][M], P[N], fpd[N], n, mx,
    prm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
map<vector<int>, int> mp;
vector<int> s[N], g[M], bt;
vector<int> seq(int a) {
  vector<int> p, vec;
  while (a > 1) {
    if (p.empty() || p.back() != fpd[a]) p.push_back(fpd[a]), vec.push_back(1);
    vec.back()++;
    a /= fpd[a];
  }
  while (vec.size() < 10) vec.push_back(1);
  sort(vec.begin(), vec.end(), greater<int>());
  return vec;
}
int zarb(vector<int> &vec) {
  int res = 1;
  for (int a : vec) res *= a;
  return res;
}
void BT(int id = 0, int res = 1, int prv = 24) {
  if (id == 10) {
    if (mp.count(bt) == 0) mp[bt] = ++n, s[n] = bt;
    return;
  }
  bt.push_back(1);
  for (int j = 0; j < prv && res < K; j++)
    BT(id + 1, res, j + 1), res *= prm[id], bt.back()++;
  bt.pop_back();
}
void BFS(int s) {
  dis[s][s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (dis[s][v] + 1 < dis[s][u]) dis[s][u] = dis[s][v] + 1, q.push(u);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(P, 1, sizeof P);
  for (int i = 2; i < N; i++)
    if (P[i])
      for (int j = i; j < N; j += i)
        if (P[j]) P[j] = 0, fpd[j] = i;
  BT();
  memset(dis, 31, sizeof dis), memset(dist, 31, sizeof dist),
      memset(ans, 31, sizeof ans);
  for (int i = 1; i <= n; i++) {
    vector<int> vec = s[i];
    mx = max(mx, zarb(vec));
    for (int j = 0; j < (int)vec.size(); j++) {
      if (j == 0 || vec[j] != vec[j - 1]) {
        vec[j]++;
        if (mp.count(vec) != 0) g[i].push_back(mp[vec]);
        vec[j]--;
      }
      if (j == (int)vec.size() - 1 || vec[j] != vec[j + 1]) {
        vec[j]--;
        if (mp.count(vec) != 0) g[i].push_back(mp[vec]);
        vec[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) BFS(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dist[i][zarb(s[j])] = min(dist[i][zarb(s[j])], dis[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= mx; k++)
        ans[i][j] = min(ans[i][j], dist[i][k] + dist[j][k]);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b, a = mp[seq(a)], b = mp[seq(b)];
    cout << ans[a][b] << "\n";
  }
  return 0;
}
