#include <bits/stdc++.h>
using namespace std;
template <class P, class Q>
void mmin(P &a, const Q &b) {
  if (b < a) a = b;
}
template <class P, class Q>
void mmax(P &a, const Q &b) {
  if (b > a) a = b;
}
template <class P, class Q>
bool mminb(P &a, const Q &b) {
  if (b < a) return a = b, true;
  return false;
}
template <class P, class Q>
bool mmaxb(P &a, const Q &b) {
  if (b > a) return a = b, true;
  return false;
}
template <class P>
P GCD(P a, P b) {
  if (a < b) swap(a, b);
  P c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
const int MAXn = 100 * 1000 + 2, MAXm = 500 + 2, INF = 1e8;
int n, m, k;
int sumc[MAXm];
int dis[MAXm][MAXm];
vector<pair<int, int> > adj[MAXn];
int comp[MAXn];
void DFS(int x, const int w) {
  comp[x] = w;
  for (int i = 0; i < ((int)(adj[x]).size()); ++i)
    if (adj[x][i].second == 0 && !comp[adj[x][i].first])
      DFS(adj[x][i].first, w);
}
inline int getInd(int x) {
  ++x;
  x = lower_bound(sumc, sumc + k, x) - sumc;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < (k); ++i) {
    cin >> sumc[i];
    sumc[i] += i ? sumc[i - 1] : 0;
  }
  for (int i = 0; i < (m); ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    --x;
    --y;
    adj[x].push_back(pair<int, int>(y, w));
    adj[y].push_back(pair<int, int>(x, w));
  }
  for (int i = 0; i < (n); ++i)
    if (!comp[i]) DFS(i, i + 1);
  for (int i = 0; i < (k); ++i)
    for (int j = (i ? sumc[i - 1] : 0); j < sumc[i] - 1; ++j)
      if (comp[i] != comp[i + 1]) {
        cout << "No" << endl;
        return 0;
      }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j) dis[i][j] = i == j ? 0 : INF;
  for (int i = 0; i < (n); ++i) {
    int x = getInd(i);
    for (int j = 0; j < ((int)(adj[i]).size()); ++j) {
      int y = getInd(adj[i][j].first);
      dis[x][y] = min(dis[x][y], adj[i][j].second);
    }
  }
  for (int z = 0; z < (k); ++z)
    for (int i = 0; i < (k); ++i)
      for (int j = 0; j < (k); ++j)
        dis[i][j] = min(dis[i][j], dis[i][z] + dis[z][j]);
  cout << "Yes" << endl;
  for (int i = 0; i < (k); ++i) {
    for (int j = 0; j < (k); ++j)
      cout << (dis[i][j] == INF ? -1 : dis[i][j]) << ' ';
    cout << endl;
  }
  return 0;
}
