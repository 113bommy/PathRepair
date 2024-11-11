#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
vector<int> vc[100001];
int vis[100001], isStorage[100001];
double denom[100001], cur[100001];
priority_queue<pair<double, int>, vector<pair<double, int> >,
               greater<pair<double, int> > >
    pq;
vector<int> res;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = (0); i < (k); ++i) {
    int v;
    cin >> v;
    vis[v] = isStorage[v] = 1;
  }
  for (int i = (0); i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    vc[x].push_back(y);
    vc[y].push_back(x);
  }
  for (int i = (1); i < (n + 1); ++i) {
    if (vis[i]) continue;
    double p = vc[i].size();
    denom[i] = 1.0 / p;
    double cnt = 0.0;
    for (int j = (0); j < (vc[i].size()); ++j) {
      if (vis[vc[i][j]] == 0) cnt += 1.0;
    }
    cnt /= p;
    cur[i] = cnt;
    pq.push(make_pair(cnt, i));
  }
  double mx = 0.0;
  int id = 0;
  while (!pq.empty()) {
    pair<double, int> p = pq.top();
    pq.pop();
    if (vis[p.second]) continue;
    vis[p.second] = 1;
    if (p.first > mx) {
      mx = p.first;
      id = p.second;
    }
    for (int i = (0); i < (vc[p.second].size()); ++i) {
      if (vis[vc[p.second][i]]) continue;
      cur[vc[p.second][i]] -= denom[vc[p.second][i]];
      pq.push(make_pair(cur[vc[p.second][i]], vc[p.second][i]));
    }
  }
  memset(vis, 0, sizeof vis);
  for (int i = (0); i < (n + 1); ++i) vis[i] = isStorage[i];
  for (int i = (1); i < (n + 1); ++i) {
    if (vis[i]) continue;
    double p = vc[i].size();
    denom[i] = 1.0 / p;
    double cnt = 0.0;
    for (int j = (0); j < (vc[i].size()); ++j) {
      if (vis[vc[i][j]] == 0) cnt += 1.0;
    }
    cnt /= p;
    cur[i] = cnt;
    pq.push(make_pair(cnt, i));
  }
  while (!pq.empty()) {
    pair<double, int> p = pq.top();
    pq.pop();
    if (vis[p.second]) continue;
    if (p.second == id) {
      for (int i = (1); i < (n + 1); ++i)
        if (vis[i] == 0) res.push_back(i);
      break;
    }
    vis[p.second] = 1;
    if (p.first > mx) {
      mx = p.first;
      id = p.second;
    }
    for (int i = (0); i < (vc[p.second].size()); ++i) {
      if (vis[vc[p.second][i]]) continue;
      cur[vc[p.second][i]] -= denom[vc[p.second][i]];
      pq.push(make_pair(cur[vc[p.second][i]], vc[p.second][i]));
    }
  }
  cout << res.size() << endl;
  for (int i = (0); i < (res.size()); ++i) cout << res[i] << " ";
  cout << endl;
}
